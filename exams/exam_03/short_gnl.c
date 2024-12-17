/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_gnl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 00:51:10 by sergio            #+#    #+#             */
/*   Updated: 2024/12/09 01:20:42 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

char    *append_char_to_line(char *line, char c, int length)
{
    char        *new_line;
    int         i;

    new_line = malloc(sizeof(char) * (length + 2));
    if (!new_line)
        return (NULL);
    i = 0;
    while(i < length)
    {
        new_line[i] = line[i];
        i++;
    }
    new_line[i++] = c;
    new_line[i] = '\0';
    free(line);
    return (new_line);
}

char    *get_next_line(int fd)
{
    static char buffer[BUFFER_SIZE];
    static int  buffer_read = 0;
    static int  buffer_pos = 0;
    char        *line = NULL;
    int         line_length = 0;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    while (1)
    {
        if (buffer_pos >= buffer_read)
        {
            buffer_read = read(fd, buffer, BUFFER_SIZE);
            buffer_pos = 0;
            if (buffer_read <= 0)
                break;
        }
        line = append_char_to_line(line, buffer[buffer_pos], line_length);
        if(!line)
            return(NULL);
        line_length++;
        if (buffer[buffer_pos++] == '\n')
            break;
    }
    if (line_length == 0)
    {
        free(line);
        return (NULL);
    }
    return (line);
}

/*
int main(int argc, char *argv[])
{
    if (argc < 2) 
    {
        printf("Uso: %s archivo1 archivo2 ...\n", argv[0]);
        return 1;
    }
    for (int i = 1; i < argc; i++) 
    {
    	int fd = open(argv[i], O_RDONLY);
    	if (fd == -1)
        {
    		perror("No se pudo abrir el archivo");
    		continue;
        }
        char *line;
        while ((line = get_next_line(fd)) != NULL)
        {
            printf("Archivo: %s - Línea leída: %s\n", argv[i], line);
            free(line);
        }
        close(fd);
    }
    return 0;
}*/
