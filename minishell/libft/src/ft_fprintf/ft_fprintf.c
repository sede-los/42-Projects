/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavila- <adavila-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 17:23:03 by adavila-          #+#    #+#             */
/*   Updated: 2024/02/18 17:23:03 by adavila-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fprintf.h"

int		fselector(va_list *args, char type, int fd);

int	ft_fprintf(int fd, const char *s, ...)
{
	va_list	args;
	size_t	p_chars;

	p_chars = 0;
	va_start(args, s);
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			p_chars += fselector(&args, *(s), fd);
		}
		else
		{
			putchar_f(*s, fd);
			p_chars++;
		}
		s++;
	}
	va_end(args);
	return (p_chars);
}

int	ft_vfprintf(int fd, const char *s, va_list *args)
{
	size_t	p_chars;

	p_chars = 0;
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			p_chars += fselector(args, *(s), fd);
		}
		else
		{
			putchar_f(*s, fd);
			p_chars++;
		}
		s++;
	}
	return (p_chars);
}

int	fselector(va_list *args, char type, int fd)
{
	size_t	w_chars;

	w_chars = 0;
	if (type == 'c')
		w_chars += printchar(va_arg(*args, int), fd);
	else if (type == 's')
		w_chars += printstr(va_arg(*args, char *), fd);
	else if (type == 'p')
		w_chars += printaddr(va_arg(*args, void *), fd);
	else if (type == 'd' || type == 'i')
		w_chars += printint(va_arg(*args, int), fd);
	else if (type == 'u')
		w_chars += printuint(va_arg(*args, unsigned int), fd);
	else if (type == 'x' || type == 'X')
		w_chars += printhex(va_arg(*args, unsigned int), type, fd);
	else if (type == '%')
		w_chars += putchar_f('%', fd);
	return (w_chars);
}
