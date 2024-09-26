/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnapp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavila- <adavila-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 14:50:11 by adavila-          #+#    #+#             */
/*   Updated: 2024/08/25 14:50:11 by adavila-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>

int	ft_strnapp(char **string, int argc, ...)
{
	int		i;
	va_list	ptr;

	if (!*string)
		return (1);
	i = 0;
	va_start(ptr, argc);
	while (i < argc)
	{
		*string = ft_strapp(*string, va_arg(ptr, char *));
		if (!*string)
			return (0);
		i++;
	}
	va_end(ptr);
	return (1);
}
