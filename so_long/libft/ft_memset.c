/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-los <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 20:39:33 by sede-los          #+#    #+#             */
/*   Updated: 2023/09/14 15:15:41 by sede-los         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char	*p;

	p = str;
	while (n-- > 0)
		*p++ = (unsigned char)c;
	return (str);
}
/*
int main() {
    char buffer[42];
    int value = '$';
    size_t size = sizeof(buffer);

    ft_memset(buffer, value, size);

    for (size_t i = 0; i < size; i++) {
        printf("%c", buffer[i]);
    }

    return 0;
}*/
