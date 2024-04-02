/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-los <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 18:33:01 by sede-los          #+#    #+#             */
/*   Updated: 2024/03/31 04:40:12 by sede-los         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*custom_free(char **str)
{
	free(*str);
	*str = NULL;
	return (NULL);
}

char	*free_stored_line(char *fd_storage)
{
	char	*new_storage;
	char	*ptr;
	int		len;

	ptr = custom_ft_strchr(fd_storage, '\n');
	if (!ptr)
	{
		new_storage = NULL;
		return (custom_free(&fd_storage));
	}
	else
		len = ptr - fd_storage + 1;
	if (!fd_storage[len])
		return (custom_free(&fd_storage));
	new_storage = custom_ft_substr(fd_storage, len,
			custom_ft_strlen(fd_storage) - len);
	custom_free(&fd_storage);
	if (!new_storage)
		return (NULL);
	return (new_storage);
}

char	*get_line(char *fd_storage)
{
	char	*line;
	char	*ptr;
	int		len;

	ptr = custom_ft_strchr(fd_storage, '\n');
	if (!ptr)
		len = custom_ft_strlen(fd_storage);
	else
		len = ptr - fd_storage + 1;
	line = custom_ft_substr(fd_storage, 0, len);
	if (!line)
		return (NULL);
	return (line);
}

char	*read_line(int fd, char *fd_storage)
{
	char	*buf;
	int		bytes_read;

	bytes_read = 1;
	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (custom_free(&fd_storage));
	while (bytes_read > 0 && !(custom_ft_strchr(fd_storage, '\n')))
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read > 0)
		{
			buf[bytes_read] = '\0';
			fd_storage = custom_ft_strjoin(fd_storage, buf);
		}
	}
	free(buf);
	if (bytes_read == -1)
		return (custom_free(&fd_storage));
	return (fd_storage);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*fd_storage;

	if (!(custom_ft_strchr(fd_storage, '\n')))
		fd_storage = read_line(fd, fd_storage);
	if (!fd_storage)
		return (NULL);
	line = get_line(fd_storage);
	if (!line)
		return (custom_free(&fd_storage));
	fd_storage = free_stored_line(fd_storage);
	return (line);
}
/*
int main(int argc, char *argv[]) {
    if (argc < 2) 
	{
        printf("Uso: %s archivo1 archivo2 ...\n", argv[0]);
        return 1;
    }
    for (int i = 1; i < argc; i++) 
	{
		int fd = open(argv[i], O_RDONLY);
		if (fd == -1) {
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
