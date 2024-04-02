/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexmay.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-los <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 22:50:05 by sede-los          #+#    #+#             */
/*   Updated: 2023/10/02 13:52:45 by sede-los         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

int	ft_printhexmay(unsigned long n, int base)
{
	char	*str;
	int		count;

	count = 0;
	str = "0123456789ABCDEF";
	if (n < (unsigned)base)
		count += ft_printchr(str[n]);
	else
	{
		count += ft_printhexmay(n / base, base);
		count += ft_printhexmay(n % base, base);
	}
	return (count);
}
