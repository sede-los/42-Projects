/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavila- <adavila-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 15:57:17 by adavila-          #+#    #+#             */
/*   Updated: 2024/09/26 18:18:28 by sede-los         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

void	free_cmd(t_cmd *cmd)
{
	t_cmd	*prev;

	if (!cmd)
		return ;
	while (cmd)
	{
		prev = cmd;
		free_lex(cmd->string);
		free_lex(cmd->redirections);
		free_tab(cmd->cmd);
		cmd = cmd->next;
		free(prev);
	}
	free(cmd);
}

t_cmd	*new_cmd(t_lex *string)
{
	t_cmd	*node;

	node = malloc(sizeof(t_cmd));
	if (!node)
		_fatal(BAD_MALLOC);
	node->string = string;
	node->cmd = NULL;
	node->redirections = NULL;
	node->heredoc_fd = 0;
	node->next = NULL;
	return (node);
}

void	add_cmd(t_cmd **head, t_cmd *node)
{
	t_cmd	*temp;

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
