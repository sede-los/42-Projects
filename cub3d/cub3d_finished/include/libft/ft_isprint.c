/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 18:21:58 by isainz-r          #+#    #+#             */
/*   Updated: 2024/01/11 09:08:50 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>
#include "libft.h"

int	ft_isprint(int c)
{
	if ((c >= 32 && c <= 126))
		return (1);
	return (0);
}

/*int	main(void)
{
	printf("El resultado del isprint es: %d\n", isprint(34));
	printf("MI ft_isprint me da: %d\n", ft_isprint(34));
}*/
