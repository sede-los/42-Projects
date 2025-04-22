/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 12:46:21 by isainz-r          #+#    #+#             */
/*   Updated: 2024/01/15 09:55:54 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = '\0';
		i++;
	}
}

/*
#include <limits.h>
int	main(void)
{
	char	ptr[5];
	char	pt[5];

//	printf("El resultado del bzero es: %s\n", bzero(ptr, 4));
//	ft_bzero(pt, 4);
//	printf("MI ft_bzero me da: %s\n", pt);
//	bzero(pt, 4);

//	int	i; &i;
//	int *i; i = malloc(sizeof(int));

	int i = 0;
	ft_memset(&i, -128, 4);
	printf("%i\n", i);
	bzero(&i, 4);
	printf("%i\n", i);
	ft_memset(&i, -128, 4);
	printf("%i\n", i);
	ft_bzero(&i, 4);
	printf("%i\n", i);
}*/
