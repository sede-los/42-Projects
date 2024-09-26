/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavila- <adavila-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 17:22:17 by adavila-          #+#    #+#             */
/*   Updated: 2024/02/18 17:22:17 by adavila-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fprintf.h"

int	printchar(char c, int fd)
{
	int	printed;

	printed = 0;
	printed += putchar_f(c, fd);
	return (printed);
}
