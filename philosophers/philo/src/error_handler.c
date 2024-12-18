/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-los <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 05:16:08 by sede-los          #+#    #+#             */
/*   Updated: 2024/10/04 05:16:11 by sede-los         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	write_error(char *str)
{
	if (!str)
		printf("Error: (null)\n");
	else
		printf("Error: %s\n", str);
	return (1);
}
