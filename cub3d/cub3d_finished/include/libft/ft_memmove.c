/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:35:03 by isainz-r          #+#    #+#             */
/*   Updated: 2024/01/19 16:35:00 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;
	const char	*a;
	char		*b;

	a = (const char *)src;
	b = (char *)dst;
	if (a > b)
	{
		i = 0;
		while (i < len)
		{
			b[i] = a[i];
			i++;
		}
	}
	else if (a < b)
	{
		while (len > 0)
		{
			b[len - 1] = a[len - 1];
			len--;
		}
	}
	return (dst);
}

/*int main ()
{
    char origen[] = "hola mundo";
    char destino[] = "2hgvjhjkjhvggvjhjk";
    printf("%s\n", ft_memmove(destino, origen, 116));
    printf("%s\n", memmove(destino, origen, 116));
    return(0);
}

*//*int	main(void)
{
	char	src1[6] = "holaa";
	char	src2[6] = "holaa";
	char	dest1[6] = "adios";
	char	dest2[6] = "adios";

	printf("El resultado del memmove es: %s\n", memmove(src2, dest2, 4));
	printf("MI ft_memmove me da: %s\n", ft_memmove(src1, dest1, 4));
//	ft_memmove(src2, dest2, 4);
//	printf("%s\n", dest2);
}*/
