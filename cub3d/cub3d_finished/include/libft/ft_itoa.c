/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 18:02:31 by isainz-r          #+#    #+#             */
/*   Updated: 2024/05/04 13:28:46 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>
#include <unistd.h>

int	ft_negative(int n)
{
	if (n < 0)
		return (0);
	return (1);
}

int	ft_count_numbers(int n)
{
	int	contador;

	contador = 0;
	if (n == INT_MIN)
		return (12);
	if (n <= INT_MAX && n > INT_MIN)
	{
		if (n < 0)
		{
			contador++;
			n = -n;
		}
		while (n >= 10)
		{
			n = n / 10;
			contador++;
		}
		contador++;
	}
	return (contador + 1);
}

char	*ft_itoa(int n)
{
	char	*number;
	int		n_number;
	long	nb;

	nb = (long)n;
	n_number = ft_count_numbers(nb);
	number = ft_calloc(n_number, sizeof(char));
	if (!number)
		return (NULL);
	if (ft_negative(nb) == 0)
	{
		number[0] = '-';
		nb = -nb;
	}
	while (nb >= 10)
	{
		number[n_number - 2] = ((nb % 10) + '0');
		nb = (nb / 10);
		n_number--;
	}
	number[n_number - 2] = ((nb % 10) + '0');
	return (number);
}

/*int	main(void)
{
	printf("%s", ft_itoa(-123456));
}*/
