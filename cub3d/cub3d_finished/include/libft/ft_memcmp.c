/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 10:43:54 by isainz-r          #+#    #+#             */
/*   Updated: 2024/01/16 10:54:44 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (((unsigned char *)s1)[i] == ((unsigned char *)s2)[i] && i + 1 < n)
		i++;
	return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
}

/*int	main(void)
{
	unsigned int	n;
	char			str1[] = "holA";
	char			str2[] = "hola";
	char			s2[] = {0, 0, 127, 0};
	char			s3[] = {0, 0, 42, 0};

	printf("%d\n", ft_memcmp(s2, s3, 4));
	printf("%d", memcmp(s2, s3, 4));
	return (0);
}*/
