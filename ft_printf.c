#include <stdarg.h>
#include <unistd.h>

int	ft_putchar(char c)
{
	write (1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return(ft_putstr("(null)"));
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

int	ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	if (!s1 || !s2)
		return (1);
	while (s1[i] && s2[i] && s1[i]==s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int	ft_strlen(char	*str)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

void	ft_puthex(unsigned int  nb, char *base, int *count)
{
	if (nb > (unsigned int)ft_strlen(base) - 1)
		ft_puthex(nb / ft_strlen(base), base, count);
	(*count) += write (1, &base[nb % ft_strlen(base)], 1);
	// (*count) += ft_putchar(nb % ft_strlen(base) + '0');
}

void	ft_putnbr(long  nb, char *base, int *count)
{
	if (nb < 0 && !ft_strcmp(base, "0123456789"))
	{
		(*count) += ft_putchar('-');
		nb *= -1;
	}
	if (nb > ft_strlen(base) - 1)
		ft_putnbr(nb / ft_strlen(base), base, count);
	(*count) += write (1, &base[nb % ft_strlen(base)], 1);
	// (*count) += ft_putchar(nb % ft_strlen(base) + '0');
}



int	ft_conditions(char *str, int count, int i, va_list vl)
{
	
	if (str[i + 1] == 's')
		count += ft_putstr(va_arg(vl, char *));
	if (str[i + 1] == 'x')
		ft_puthex(va_arg(vl, unsigned int), "0123456789abcdef", &count);
	if (str[i + 1] == 'd')
		ft_putnbr(va_arg(vl, int), "0123456789", &count);
	if (str[i + 1] == '%')
		count += ft_putchar('%');
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		count;
	va_list	vl;

	va_start(vl, str);
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			count = ft_conditions((char *)str, count, i, vl);
			i++;
		}
		else
			count += ft_putchar(str[i]);
		i++;
	}
	va_end(vl);
	return (count);
}

