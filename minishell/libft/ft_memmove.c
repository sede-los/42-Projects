/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-los <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 18:07:20 by sede-los          #+#    #+#             */
/*   Updated: 2023/09/14 20:11:53 by sede-los         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <stddef.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	int					i;

	d = dest;
	s = src;
	if (!dest && !src)
		return (NULL);
	if (d < s)
	{
		i = 0;
		while (i++ < (int)n)
			d[i - 1] = s[i - 1];
	}
	else if (d > s)
	{
		i = n - 1;
		while (i-- >= 0)
			d[i + 1] = s[i + 1];
	}
	return (dest);
}
/*
int main(void)
{
    char src[] = "Hello, world!";
    char dest2[20];
    char dest1[20];
    size_t n = 7; // Número de bytes a copiar

    // Usar la función estándar memmove
    printf("Antes de memmove:\n");
    printf("src:  %s\n", src);
    printf("dest1: %s\n", dest1);
    memmove(dest1, src, n);
    printf("Después de memmove:\n");
    printf("src:  %s\n", src);
    printf("dest1: %s\n\n", dest1);

    // Usar tu implementación ft_memmove
    printf("Antes de ft_memmove:\n");
    printf("src:  %s\n", src);
    printf("dest2: %s\n", dest2);
    ft_memmove(dest2, src, n);
    printf("Después de ft_memmove:\n");
    printf("src:  %s\n", src);
    printf("dest2: %s\n", dest2);

    return 0;
}*/
