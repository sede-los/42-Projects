/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:01:03 by isainz-r          #+#    #+#             */
/*   Updated: 2024/05/26 12:06:04 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_aux(char *aux)
{
	int		i;
	int		j;
	char	*r_aux;

	j = 0;
	i = 0;
	while (aux[j] != '\0')
		j++;
	while (aux[i] != '\n' && aux[i] != '\0')
		i++;
	if (aux[i] == '\n')
		i++;
	r_aux = ft_substr_gnl(aux, i, j);
	if (!r_aux)
		return (free(aux), NULL);
	free(aux);
	return (r_aux);
}

char	*ft_line(char *aux)
{
	int		i;
	char	*line;

	i = 0;
	while (aux[i] != '\n' && aux[i] != '\0')
		i++;
	if (aux[i] == '\n')
		i++;
	line = ft_substr_gnl(aux, 0, i);
	if (!line)
		return (0);
	return (line);
}

char	*ft_read(int fd, char *text)
{
	int		n_bytes;
	char	*buffer;
	char	*aux;

	buffer = ft_calloc_gnl(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	n_bytes = 1;
	while (!ft_strchr_gnl(text, '\n') && n_bytes)
	{
		n_bytes = read(fd, buffer, BUFFER_SIZE);
		if (n_bytes < 0)
			return (free(buffer), free(text), NULL);
		if (n_bytes == 0)
			return (free(buffer), text);
		buffer[n_bytes] = '\0';
		aux = text;
		text = ft_strjoin_gnl(text, buffer);
		free(aux);
	}
	free(buffer);
	buffer = NULL;
	return (text);
}

char	*get_next_line(int fd)
{
	static char	*text = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= INT_MAX)
		return (NULL);
	text = ft_read(fd, text);
	if (!text)
		return (text = NULL, NULL);
	if (!text[0])
		return (free(text), text = NULL, NULL);
	line = ft_line(text);
	if (!line)
		return (free(text), text = NULL, NULL);
	text = ft_aux(text);
	return (line);
}
