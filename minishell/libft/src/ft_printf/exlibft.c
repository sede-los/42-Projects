/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exlibft.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavila- <adavila-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 17:11:34 by adavila-          #+#    #+#             */
/*   Updated: 2024/02/18 17:11:34 by adavila-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_fd_f(long int n)
{
	int	modulo;

	modulo = n % 10;
	n /= 10;
	if (n < 0 || modulo < 0)
	{
		ft_printf("-");
		modulo *= -1;
		n *= -1;
	}
	if (n > 0)
	{
		ft_putnbr_fd_f(n);
		ft_printf("%c", modulo + '0');
	}
	else
	{
		ft_printf("%c", modulo + '0');
	}
}

int	ft_putchar_f(int c)
{
	write(1, &c, 1);
	return (1);
}

int	null_value(long n, t_format format)
{
	if (n == 0 && format.precision == 0 && format.precision_dot)
	{
		if (format.l_offset || format.r_offset)
			return (' ');
		else
			return (0);
	}
	return (1);
}
