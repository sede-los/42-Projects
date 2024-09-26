/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavila- <adavila-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 17:29:23 by adavila-          #+#    #+#             */
/*   Updated: 2024/02/18 17:29:23 by adavila-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fprintf.h"

int	printint(long n, int fd)
{
	int	t_length;

	t_length = int_length(n);
	putnbr_fd_f(n, fd);
	return (t_length);
}
