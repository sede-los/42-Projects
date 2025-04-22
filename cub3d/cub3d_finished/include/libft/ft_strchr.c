/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:46:24 by isainz-r          #+#    #+#             */
/*   Updated: 2024/01/29 18:36:24 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if ((char)c == '\0')
		return ((char *) &s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *) &s[i]);
		i++;
	}
	return (0);
}

/*int	main(void)
{
	printf("%s\n", ft_strchr("hola", 'l'));
	printf("%s\n", strchr("hola", 'l'));
}*/
