/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-los <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 20:11:22 by sede-los          #+#    #+#             */
/*   Updated: 2023/09/14 17:46:50 by sede-los         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
/*
int main()
{
    const char *cadena = "Hola, mundo!";

    size_t longitud = ft_strlen(cadena);
    printf("La longitud de la cadena es: %zu\n", longitud);

    return 0;
}*/
