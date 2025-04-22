/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 18:04:59 by isainz-r          #+#    #+#             */
/*   Updated: 2024/01/11 09:00:31 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>
#include "libft.h"

int	ft_isascii(int c)
{
	if ((c >= 0 && c <= 127))
		return (1);
	return (0);
}

/*int	main(void)
{
	printf("El resultado del isascii es: %d\n", isascii(0));
	printf("MI ft_isascii me da: %d\n", ft_isascii(0));
}*/
