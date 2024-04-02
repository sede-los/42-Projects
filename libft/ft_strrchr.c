/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-los <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 21:18:07 by sede-los          #+#    #+#             */
/*   Updated: 2023/09/14 22:38:02 by sede-los         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ret;

	ret = NULL;
	while (*s)
	{
		if (*s == (unsigned char)c)
			ret = (char *)s;
		s++;
	}
	if ((unsigned char)c == '\0')
	{
		while (*s)
			s++;
		return ((char *)s);
	}
	return (ret);
}
