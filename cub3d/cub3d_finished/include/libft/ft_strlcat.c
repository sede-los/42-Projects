/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:51:25 by isainz-r          #+#    #+#             */
/*   Updated: 2024/01/15 09:57:21 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len_dst;
	size_t	len_src;
	size_t	j;

	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	j = 0;
	if (dstsize <= len_dst)
		return (len_src + dstsize);
	while (src[j] != '\0' && j < dstsize - len_dst - 1)
	{
		dst[len_dst + j] = src[j];
		j++;
	}
	dst[len_dst + j] = '\0';
	return (len_dst + len_src);
}

/*int	main(void)
{
	unsigned int	nb;
	char			src1[20] = "hola";
	char			dst1[20] = "qwerty";
	char			src2[20] = "hola";
	char			dst2[20] = "qwerty";

	//ft_strncat (str1, str2, 3);
	printf("%lu\n", ft_strlcat(dst2, src2, 3));
	printf("%s\n", dst2);
	printf("%lu\n", strlcat(dst1, src2, 3));
	printf("%s\n", dst1);
	return (0);
}*/
