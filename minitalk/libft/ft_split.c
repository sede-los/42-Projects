/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-los <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 01:49:30 by sede-los          #+#    #+#             */
/*   Updated: 2023/09/18 17:57:03 by sede-los         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	count_words(const char *str, char c)
{
	int			flag;
	int			count;
	const char	*aux;

	aux = str;
	flag = 0;
	count = 0;
	while (*aux)
	{
		if (*aux == c && flag)
			flag = 0;
		if (*aux != c && !flag)
		{
			count++;
			flag++;
		}
		aux++;
	}
	return (count);
}

static int	custom_len(const char *s, char c)
{
	const char	*aux;
	int			len;

	aux = s;
	len = 0;
	while (*aux)
	{
		if (*aux == c)
			return (len);
		len++;
		aux++;
	}
	return (len);
}

static void	cpy_str(char *dst, const char *src, int len)
{
	int	i;

	i = -1;
	while (++i < len && src[i])
		dst[i] = src[i];
	dst[i] = '\0';
}

static void	free_mem_tab(char **tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(tab[i]);
		i++;
	}
	free (tab);
}

char	**ft_split(const char *s, char c)
{
	char		**tab;
	int			i;
	int			j;

	j = count_words(s, c);
	tab = (char **)malloc(sizeof(char *) * (j + 1));
	if (!tab)
		return (NULL);
	i = 0;
	while (*s && j > 0)
	{
		if (!custom_len(s, c))
			s++;
		else
		{
			tab[i++] = (char *)malloc(sizeof(char) * custom_len(s, c) + 1);
			if (!tab[i - 1])
				return (free_mem_tab(tab, i), NULL);
			cpy_str(tab[i - 1], s, custom_len(s, c));
			s = s + custom_len(s, c);
			j--;
		}
	}
	tab[i] = NULL;
	return (tab);
}
