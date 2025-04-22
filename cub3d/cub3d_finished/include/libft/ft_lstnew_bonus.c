/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 18:57:27 by isainz-r          #+#    #+#             */
/*   Updated: 2024/05/26 11:57:17 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*element;

	element = (t_list *)malloc(sizeof(t_list));
	if (!element)
		return (0);
	element->content = (void *)content;
	element->next = NULL;
	return (element);
}

/*int main()
{
    int *data = (int *)malloc(sizeof(int));
    *data = 42;

    t_list *newElement = ft_lstnew(data);
    if (newElement != NULL)
    {
        printf("Contenido: %d\n", *((int *)newElement->content));
        free(data);
        free(newElement);
    }
}*/
