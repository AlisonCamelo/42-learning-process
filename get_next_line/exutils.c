/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_lineEEEE.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamelo <acamelo@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 18:55:54 by acamelo           #+#    #+#             */
/*   Updated: 2026/07/31 13:28:14 by acamelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "get_next_line.h"
//#include <stdio.h>
//#include <fcntl.h>
/*
void	ft_bzero(void *s, size_t n)
{
	unsigned char	*fillzero;
	size_t			counter;

	fillzero = (unsigned char *)s;
	counter = 0;
	while (counter < n)
	{
		fillzero[counter] = '\0';
		counter++;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*str;
	size_t	totalsize;

	if (size != 0 && (size_t)-1 / size < nmemb)
		return (NULL);
	totalsize = nmemb * size;
	str = (malloc(totalsize));
	if (str == NULL)
		return (NULL);
	ft_bzero(str, totalsize);
	return (str);
}

size_t ft_strlen(char *str)
{
    size_t i;
    
    i = 0;
    while(str[i] != '\0' && str[i] != NULL)
        i++;
    return(i);
}

char *get_next_line(int fd)
{
    static char * leftovers;
    char *buffer;
    size_t count_bytes;
    size_t read_bytes;
    size_t i;
    
    if(leftovers != NULL)
        count_bytes = ft_strlen(leftovers); // size of leftovers
    else
        count_bytes = 0;
    buffer = ft_calloc((BUFFER_SIZE + 1), (sizeof(char))); //Allocate memory accordingly
    if (buffer == NULL) // si buffer es nulL RETORNA NULL, PARA EVITAR PROBLEMAS POSTERIORES
        return(NULL);
    read_bytes = read(fd, buffer, BUFFER_SIZE); //read 3 characters each time from a file    
    if (read_bytes <= 0)
    {    
        free(buffer);
        return(NULL); //Stop when read 0 or less bytes
    }
    i = 0;
    while (read_bytes < count_bytes)
    {
        buffer[i] = leftovers[i];
        i++;
    }
    if(leftovers)
        free(leftovers);
    leftovers = buffer;    
    return(leftovers);
}
int main()
{
    int    fd;
    char  *next_line;
    int  count;

    count = 0;    
    fd = open("example.txt", O_RDONLY);
    next_line = get_next_line(fd);
    printf("[%d]:%s\n", count, next_line);

    close(fd);
    free(next_line);
    return (0);
}
*/








