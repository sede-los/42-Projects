/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:43:46 by isainz-r          #+#    #+#             */
/*   Updated: 2024/01/15 12:57:37 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	contador;

	i = 0;
	contador = 0;
	while (src[i] != '\0' && contador + 1 < dstsize)
	{
		dst[i] = src[i];
		i++;
		contador++;
	}
	if (dstsize != 0)
		dst[i] = '\0';
	while (src[i] != '\0')
	{
		i++;
		contador++;
	}
	return (contador);
}

/*int	main(void)
{
	unsigned int	n;
	char			dst1[100];
	char            dst2[100];
	char			*src1;
	char            *src2;

	src1 = "123456789";
	src2 = "123456789";
	//ft_strlcpy(str1, str2, 5);
	printf("%zu\n", ft_strlcpy(dst2, src2, 5));
	printf("%s\n", dst2);
	printf("%lu\n", strlcpy(dst1, src1, 5));
	printf("%s\n", dst1);
	return (0);
}*/
