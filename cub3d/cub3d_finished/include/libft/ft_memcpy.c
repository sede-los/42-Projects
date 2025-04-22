/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 15:04:09 by isainz-r          #+#    #+#             */
/*   Updated: 2024/05/04 13:24:00 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dst && !src)
		return (0);
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dst);
}

/*int	main(void)
{
	char	src1[6] = "";
	char	src2[6] = "";
	char	dest1[6] = "";
	char	dest2[6] = "";

	printf("El resultado del memcpy es: %s\n", memcpy(src1, dest1, 4));
	printf("MI ft_memcpy me da: %s\n", ft_memcpy(src1, dest2, 4));
}*/
