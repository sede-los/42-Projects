/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printuint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavila- <adavila-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 17:32:49 by adavila-          #+#    #+#             */
/*   Updated: 2024/02/18 17:32:49 by adavila-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fprintf.h"

static void	putunbr_fd(unsigned long n, int fd);

int	printuint(unsigned int u_int, int fd)
{
	int	t_length;

	t_length = uint_length(u_int);
	putunbr_fd(u_int, fd);
	return (t_length);
}

static void	putunbr_fd(unsigned long n, int fd)
{
	int	modulo;

	modulo = n % 10;
	n /= 10;
	if (n > 0)
	{
		putunbr_fd(n, fd);
		putchar_f(modulo + '0', fd);
	}
	else
	{
		putchar_f(modulo + '0', fd);
	}
}
