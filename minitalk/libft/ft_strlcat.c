/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-los <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 19:57:21 by sede-los          #+#    #+#             */
/*   Updated: 2023/09/14 18:54:26 by sede-los         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stddef.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	ret;
	size_t	i;

	i = 0;
	while (*dst && i < size)
	{
		++dst;
		++i;
	}
	ret = ft_strlcpy(dst, src, size - i);
	return (ret + i);
}
