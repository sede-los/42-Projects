/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 10:52:45 by isainz-r          #+#    #+#             */
/*   Updated: 2024/10/18 12:32:20 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdint.h>

void	*ft_calloc_gnl(size_t count, size_t size)
{
	unsigned char	*pointer;
	size_t			i;

	if (count == SIZE_MAX || size == SIZE_MAX)
		return (0);
	pointer = malloc(count * size);
	if (!pointer)
		return (NULL);
	i = 0;
	while (i < count * size)
	{
		pointer[i] = '\0';
		i++;
	}
	return ((void *)pointer);
}

size_t	ft_strlen_gnl(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin_gnl(char const *s1, char const *s2)
{
	char	*resultado;
	size_t	i;
	size_t	j;
	size_t	len_s1;
	size_t	len_s2;

	i = 0;
	j = 0;
	len_s1 = ft_strlen_gnl(s1);
	len_s2 = ft_strlen_gnl(s2);
	resultado = ft_calloc_gnl(len_s1 + len_s2 + 1, 1);
	if (!resultado)
		return (NULL);
	while (i < len_s1 && s1[0] != '\0')
		resultado[j++] = s1[i++];
	i = 0;
	while (i < len_s2 && s2[0] != '\0')
		resultado[j++] = s2[i++];
	return (resultado);
}

char	*ft_strchr_gnl(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if ((char)c == '\0')
		return ((char *) &s[ft_strlen_gnl(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *) &s[i]);
		i++;
	}
	return (0);
}

char	*ft_substr_gnl(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*sub_string;

	if (start > ft_strlen_gnl(s) || s[0] == '\0' || len == 0)
	{
		sub_string = ft_calloc_gnl(1, sizeof(char));
		if (!sub_string)
			return (NULL);
		sub_string[0] = '\0';
		return ((char *)sub_string);
	}
	if (len > (ft_strlen_gnl(s) - start))
		len = ft_strlen_gnl(s) - start;
	sub_string = ft_calloc_gnl(len + 1, sizeof(char));
	if (!sub_string)
		return (NULL);
	i = 0;
	while (i < len)
		sub_string[i++] = s[start++];
	sub_string[i] = '\0';
	return ((char *)sub_string);
}
