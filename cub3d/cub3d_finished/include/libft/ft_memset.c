/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:28:27 by isainz-r          #+#    #+#             */
/*   Updated: 2024/01/15 09:55:34 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((char *)b)[i] = c;
		i++;
	}
	return (b);
}

/*int	main(void)
{
	char	ptr[5];

	printf("El resultado del memset es: %s\n", memset(ptr, 'r', (0)));
	printf("MI ft_memset me da: %s\n", ft_memset(ptr, 'r', 0));
}*/
