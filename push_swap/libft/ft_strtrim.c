/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-los <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 22:42:02 by sede-los          #+#    #+#             */
/*   Updated: 2023/09/15 01:21:59 by sede-los         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	is_sep(char c, char const *set)
{
	size_t		i;
	const char	*aux;

	i = 0;
	aux = set;
	while (aux[i])
	{
		if ((int)c == (int)aux[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*str;
	size_t		i;
	const char	*start;
	const char	*end;

	start = s1;
	end = start + ft_strlen(s1) - 1;
	while (*start && is_sep(*start, set))
		start++;
	while (end > start && is_sep(*end, set))
		end--;
	str = malloc(sizeof(char) * (end - start + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (start <= end)
		str[i++] = *start++;
	str[i] = '\0';
	return (str);
}
