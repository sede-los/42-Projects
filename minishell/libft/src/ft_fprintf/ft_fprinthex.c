/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavila- <adavila-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 17:28:45 by adavila-          #+#    #+#             */
/*   Updated: 2024/02/18 17:28:45 by adavila-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fprintf.h"

int	printhex(long n, char type, int fd)
{
	int	t_length;

	t_length = hex_count(n);
	to_hex(n, type, fd);
	return (t_length);
}
