/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 11:01:51 by isainz-r          #+#    #+#             */
/*   Updated: 2024/05/04 13:27:40 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	int		len;
	char	*new_string;
	int		i;

	i = 0;
	len = ft_strlen(s1);
	new_string = malloc(len + 1);
	if (!new_string)
		return (NULL);
	new_string[len] = 0;
	while (i < len)
	{
		new_string[i] = s1[i];
		i++;
	}
	return (new_string);
}

/*int main(void)
{
    printf("%s\n", ft_strdup("asdfghjklñ"));
//    printf("%s\n", new_string);
	printf("%s\n", strdup("asdfghjklñ"));
}*/
