/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavila- <adavila-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 11:12:24 by adavila-          #+#    #+#             */
/*   Updated: 2024/02/13 11:12:24 by adavila-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fprintf.h"

int	printstr(const char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return (ft_fprintf(fd, "(null)"));
	while (s[i])
	{
		putchar_f(s[i], fd);
		i++;
	}
	return (i);
}
