/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printaddr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavila- <adavila-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 17:19:24 by adavila-          #+#    #+#             */
/*   Updated: 2024/02/18 17:19:24 by adavila-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fprintf.h"

int	printaddr(void *addr, int fd)
{
	int	t_length;

	t_length = 0;
	if (addr == NULL)
	{
		t_length += ft_fprintf(fd, "(nil)");
		return (t_length);
	}
	t_length = ft_fprintf(fd, "0x");
	t_length += hex_count((unsigned long) addr);
	to_hex((unsigned long)addr, 'p', fd);
	return (t_length);
}
