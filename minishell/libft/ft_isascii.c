/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-los <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 19:04:10 by sede-los          #+#    #+#             */
/*   Updated: 2023/09/12 20:49:10 by sede-los         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	ft_isascii(int c)
{	
	return (c >= 0 && c <= 127);
}
/*
int main(void)
{
    int ch = 'A';

    if (ft_isascii(ch)) {
        printf("%c es un carácter ASCII válido.\n", ch);
    } else {
        printf("%c no es un carácter ASCII válido.\n", ch);
    }

    return 0;
}*/
