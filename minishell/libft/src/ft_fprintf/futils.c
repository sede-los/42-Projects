/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavila- <adavila-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 17:33:44 by adavila-          #+#    #+#             */
/*   Updated: 2024/02/18 17:33:44 by adavila-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fprintf.h"

void	to_hex(unsigned long n, int mode, int fd)
{
	char	digit;
	char	flag;

	if (mode == 'x' || mode == 'p')
		flag = 'a';
	else if (mode == 'X')
		flag = 'A';
	digit = n % 16;
	if (n == 0)
		putchar_f('0', fd);
	if (n > 0)
	{
		if (n / 16 != 0)
			to_hex(n / 16, mode, fd);
		if (digit >= 10)
			digit = digit - 10 + flag;
		else
			digit = digit + '0';
		putchar_f(digit, fd);
	}
}

int	int_length(long int n)
{
	int	count;

	count = 0;
	if (n == 0)
		count++;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

int	uint_length(unsigned int n)
{
	int	count;

	count = 0;
	if (n == 0)
		count++;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

int	hex_count(unsigned long n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 16;
		count++;
	}
	return (count);
}
