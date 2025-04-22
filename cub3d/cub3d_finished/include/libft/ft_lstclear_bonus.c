/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:30:01 by isainz-r          #+#    #+#             */
/*   Updated: 2024/05/26 11:58:52 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del) (void *))
{
	t_list	*temp;

	if (!lst || !*lst)
		return ;
	while (*lst != NULL)
	{
		temp = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = temp;
	}
	*lst = NULL;
}
/*
	while (lst != NULL)
	{
		temp = lst->content;
		lst = lst->next;
		del(temp);
	}
	lst->next = NULL;
	free(lst);
}*/
