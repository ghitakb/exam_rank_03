#include <unistd.h>
#include <stdlib.h>

char *get_next_line(int fd)
{
    int 	i = 0;
    int 	rd = 0;
    char	character;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
    char 	*buffer = malloc(1000000);

    while ((rd = read(fd, &character, 1)) > 0)
    {
        buffer[i++] = character;
        if (character == '\n')
            break;
    }
    if ((!buffer[i - 1] && !rd) || rd == -1)
    {
        free(buffer);
        return (NULL); 
    }
    buffer[i] =  '\0';
    return(buffer);
}