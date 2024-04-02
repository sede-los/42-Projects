/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-los <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 18:47:49 by sede-los          #+#    #+#             */
/*   Updated: 2024/03/31 04:42:17 by sede-los         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	custom_ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*custom_ft_strchr(char *str, int c)
{
	if (!str)
		return (NULL);
	while (*str != (unsigned char)c)
		if (!*str++)
			return (0);
	return ((char *)str);
}

char	*custom_ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		c;

	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char));
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	str = malloc(sizeof(char)
			* (custom_ft_strlen(s1) + custom_ft_strlen(s2) + 1));
	if (!str)
		return (custom_free(&s1));
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	c = -1;
	while (s2[++c])
		str[i + c] = s2[c];
	str[i + c] = '\0';
	free(s1);
	return (str);
}

char	*custom_ft_substr(char *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	s_len;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	s_len = custom_ft_strlen(s);
	if (start >= s_len)
	{
		ret = malloc(1);
		if (ret)
			ret[0] = '\0';
		return (ret);
	}
	if (len > s_len - start)
		len = s_len - start;
	ret = malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (NULL);
	while (start < s_len && i < len && s[start])
		ret[i++] = s[start++];
	ret[i] = '\0';
	return (ret);
}
