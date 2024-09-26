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

#include "ft_fprintf.h"

void	putnbr_fd_f(long int n, int fd)
{
	int	modulo;

	modulo = n % 10;
	n /= 10;
	if (n < 0 || modulo < 0)
	{
		putchar_f('-', fd);
		modulo *= -1;
		n *= -1;
	}
	if (n > 0)
	{
		putnbr_fd_f(n, fd);
		putchar_f(modulo + '0', fd);
	}
	else
	{
		putchar_f(modulo + '0', fd);
	}
}

int	putchar_f(int c, int fd)
{
	write(fd, &c, 1);
	return (1);
}
