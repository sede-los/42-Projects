/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:16:36 by isainz-r          #+#    #+#             */
/*   Updated: 2024/01/26 14:29:50 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*void    ft_tou(unsigned int i, char *c)
{
	c[i] = c[i] -32;
}*/

void	ft_striteri(char *s, void (*f) (unsigned int, char*))
{
	unsigned int		i;

	i = -1;
	while (s[++i] != '\0')
	{
		f(i, &s[i]);
	}
}

/*int main(void)
{
	char s[20] = "hola_Mundo";
	ft_striteri(s, ft_tou);
	printf("%s", s);
}*/
