/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-los <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 20:01:24 by sede-los          #+#    #+#             */
/*   Updated: 2023/09/12 20:49:40 by sede-los         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}
/*
int main()
{
    int ch = '';

    if (ft_isprint(ch)) {
        printf("%c es un carácter imprimible.\n", ch);
    } else {
        printf("%c no es un carácter imprimible.\n", ch);
    }

    return 0;
}*/
