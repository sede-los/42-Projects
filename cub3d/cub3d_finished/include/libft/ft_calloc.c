/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 11:00:30 by isainz-r          #+#    #+#             */
/*   Updated: 2024/05/04 13:26:58 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdint.h>

void	*ft_calloc(size_t count, size_t size)
{
	char	*pointer;
	size_t	i;

	if (count == SIZE_MAX || size == SIZE_MAX)
		return (0);
	pointer = malloc(count * size);
	if (!pointer)
		return (NULL);
	i = 0;
	while (i < count * size)
	{
		pointer[i] = '\0';
		i++;
	}
	return ((void *)pointer);
}

/*
int	main(void)
{
	printf("%p\n", ft_calloc(39999, 400));
	printf("%p\n", calloc(39999, 400));

}

int main(void)
{
  char *ptr;
  ptr = ft_calloc(10, sizeof(char));
  if (ptr == NULL)
    return 1;
  ft_strlcpy(ptr, "Hola", 5);
  printf("%s\n", ptr);
  free(ptr);
  return 0;
}*/
