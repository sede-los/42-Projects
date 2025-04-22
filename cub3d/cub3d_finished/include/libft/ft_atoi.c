/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 10:49:17 by isainz-r          #+#    #+#             */
/*   Updated: 2024/01/15 10:06:06 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int	ft_atoi(const char *str)
{
	int	nb;
	int	i;
	int	s;

	nb = 0;
	i = 0;
	s = 0;
	while (str[i] == ' ' || (str[i] <= 13 && str[i] >= 9))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i + 1] == '+' || str[i + 1] == '-')
			return (0);
		if (str[i] == '-')
			s++;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	if (s % 2 == 1)
		nb = -nb;
	return (nb);
}

/*int	main(void)
{
	char    s1[20] = "	-+----123 45";
	printf("%i\n", atoi(s1));
	printf("%i\n", ft_atoi(s1));
	return (0);
}*/
