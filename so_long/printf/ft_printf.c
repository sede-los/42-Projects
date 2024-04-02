/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-los <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 18:28:19 by sede-los          #+#    #+#             */
/*   Updated: 2023/09/26 00:58:19 by sede-los         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include "ft_printf.h"
#include <limits.h>

int	print_format(char specifier, va_list ap)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count += ft_printchr(va_arg(ap, int));
	else if (specifier == 's')
		count += ft_printstr(va_arg(ap, char *));
	else if (specifier == 'p')
	{
		count += write(1, "0x", 2);
		count += ft_printptr((void *)va_arg(ap, void *));
	}
	else if (specifier == 'd')
		count += ft_printnbr((long)(va_arg(ap, int)), 10);
	else if (specifier == 'i')
		count += ft_printnbr((long)(va_arg(ap, int)), 10);
	else if (specifier == 'u')
		count += ft_printunsnbr((long)(va_arg(ap, unsigned int)), 10);
	else if (specifier == 'x')
		count += ft_printhex((long)(va_arg(ap, unsigned int)), 16);
	else if (specifier == 'X')
		count += ft_printhexmay((long)(va_arg(ap, unsigned int)), 16);
	else if (specifier == '%')
		count += write(1, "%", 1);
	return (count);
}

int	ft_printf(char const *format, ...)
{
	va_list	ap;
	int		count;

	va_start(ap, format);
	count = 0;
	while (*format != '\0')
	{
		if (*format == '%')
			count += print_format(*(++format), ap);
		else
			count += write(1, format, 1);
		format++;
	}
	va_end (ap);
	return (count);
}
