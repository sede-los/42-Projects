/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:38:09 by isainz-r          #+#    #+#             */
/*   Updated: 2024/06/10 20:24:01 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
			return ((void *)s + i);
		i++;
	}
	return (NULL);
}

/*int	main(void)
{
	unsigned int	n;
	char	str1[] = "holA";
	char	str2 = 'r';
	char	s[] = {0, 1, 2, 3, 4, 5};

	printf("%p\n", ft_memchr(s, 0, 1));
	printf("%p\n", memchr(s, 0, 1));
	return (0);
}*/
