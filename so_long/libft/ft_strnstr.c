/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-los <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 17:20:18 by sede-los          #+#    #+#             */
/*   Updated: 2023/09/14 22:19:18 by sede-los         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"
#include <string.h>
#include <stdio.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needle_len;

	if (*needle == '\0')
		return ((char *)haystack);
	needle_len = ft_strlen(needle);
	while (*haystack && len >= needle_len)
	{
		if (ft_strncmp(haystack, needle, needle_len) == 0)
			return ((char *)haystack);
		haystack++;
		len--;
	}
	return (NULL);
}
/*
int main(void)
{
    const char *haystack = "Hello, world!";
    const char *needle = "world";
    size_t len = 13; // Longitud máxima a buscar

    // Usar la función estándar strnstr
    char *result1 = strnstr(haystack, needle, len);
    printf("strnstr Resultado estándar: %s\n", result1);

    // Usar tu implementación ft_strnstr
    char *result2 = ft_strnstr(haystack, needle, len);
    printf("ft_strnstr Resultado: %s\n", result2);

    return 0;
}*/
