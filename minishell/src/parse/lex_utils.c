/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavila- <adavila-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 15:56:46 by adavila-          #+#    #+#             */
/*   Updated: 2024/08/16 15:56:46 by adavila-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_lex(t_lex *string)
{
	t_lex	*prev;

	if (!string)
		return ;
	while (string)
	{
		prev = string;
		free(string->word);
		string = string->next;
		free(prev);
	}
}

t_lex	*new_lex(char *str, int type)
{
	t_lex	*node;

	node = malloc(sizeof(t_lex));
	if (!node || !str)
		_fatal(BAD_MALLOC);
	node->word = str;
	node->type = type;
	node->next = NULL;
	return (node);
}

void	lex_add(t_lex **head, t_lex *node)
{
	t_lex	*temp;

	if (head == NULL)
		return ;
	if (*head == NULL)
	{
		*head = node;
		return ;
	}
	temp = *head;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = node;
}

void	lex_remove(t_lex **to_delete, t_lex **prev, t_lex **head)
{
	t_lex	*temp;

	temp = *to_delete;
	if (!*prev)
	{
		(*to_delete) = (*to_delete)->next;
		*head = *to_delete;
		free(temp->word);
		free(temp);
		return ;
	}
	(*prev)->next = (*to_delete)->next;
	(*to_delete) = (*to_delete)->next;
	free(temp->word);
	free(temp);
	return ;
}
