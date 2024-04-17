/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-los <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 22:50:05 by sede-los          #+#    #+#             */
/*   Updated: 2023/10/02 13:50:26 by sede-los         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

int	ft_printunsnbr(unsigned long n, int base)
{
	char	*str;
	int		count;

	count = 0;
	str = "0123456789abcdef";
	if (n < (unsigned int)base)
		count += ft_printchr(str[n]);
	else
	{
		count += ft_printunsnbr(n / base, base);
		count += ft_printunsnbr(n % base, base);
	}
	return (count);
}
