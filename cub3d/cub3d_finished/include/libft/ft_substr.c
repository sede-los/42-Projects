/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 11:48:56 by isainz-r          #+#    #+#             */
/*   Updated: 2024/01/30 20:49:23 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*sub_string;

	if (start > ft_strlen(s) || s[0] == '\0' || len == 0)
	{
		sub_string = ft_calloc(1, sizeof(char));
		if (sub_string == NULL)
			return (NULL);
		sub_string[0] = '\0';
		return ((char *)sub_string);
	}
	if (len > (ft_strlen(s) - start))
		len = ft_strlen(s) - start;
	sub_string = ft_calloc(len + 1, sizeof(char));
	if (sub_string == NULL)
		return (NULL);
	i = 0;
	while (i < len)
		sub_string[i++] = s[start++];
	sub_string[i] = '\0';
	return ((char *)sub_string);
}

/*int main(void)
{
	printf("%s\n", ft_substr("lorem ipsum dolor sit amet", 7, 10));
}*/
