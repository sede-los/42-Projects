/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavila- <adavila-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 17:46:27 by adavila-          #+#    #+#             */
/*   Updated: 2024/09/26 18:19:16 by sede-los         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	cmd_len(t_lex *string)
{
	int		i;
	t_lex	*temp;

	i = 0;
	temp = string;
	while (temp)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}

/*Strip all redirections off the token list,
  freeing and reassigning pointers on the 
  underlying list*/
t_lex	*strip_redirections(t_lex **string)
{
	t_lex	*redirections;
	t_lex	*prev;
	t_lex	*temp;
	t_lex	*node;

	prev = NULL;
	temp = *string;
	redirections = NULL;
	while (temp && temp->type != PIPE)
	{
		if (temp->type == LESS || temp->type == DLESS
			|| temp->type == GREAT || temp->type == DGREAT)
		{
			node = new_lex(ft_strdup(temp->next->word), temp->type);
			lex_add(&redirections, node);
			lex_remove(&temp, &prev, string);
			lex_remove(&temp, &prev, string);
			continue ;
		}
		prev = temp;
		temp = temp->next;
	}
	return (redirections);
}
