/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 00:35:37 by isainz-r          #+#    #+#             */
/*   Updated: 2024/05/26 11:57:43 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (0);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

/*typedef struct s_list
{
    void *content;
    struct s_list *next;
} t_list;*/
/*
t_list	*ft_lstlast(t_list *lst)
{
	int	i;

	i = 0;
	while (lst[i] != NULL)
		i++;
	return (lst[i]);
}
*/
/*int main()
{
	t_list *element1 = malloc(sizeof(t_list));
    t_list *element2 = malloc(sizeof(t_list));

    element1->content = "Elemento 1";
    element2->content = "Elemento 2";
    element1->next = NULL;
    element2->next = NULL;
    t_list *lista = element1;
    ft_lstsize(&lista);
    t_list *current = lista;
    while (current != NULL)
    {
        printf("Contenido: %s\n", (char *)current->content);
        current = current->next;
    }
    free(element1);
    free(element2);
}*/
