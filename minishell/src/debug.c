/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavila- <adavila-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 15:56:29 by adavila-          #+#    #+#             */
/*   Updated: 2024/08/16 15:56:29 by adavila-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*token_value(int token_val)
{
	if (token_val == DLESS)
		return ("redir: here doc");
	if (token_val == LESS)
		return ("redir: input file");
	if (token_val == DGREAT)
		return ("redir: output file (append)");
	if (token_val == GREAT)
		return ("redir: output file (truncate)");
	if (token_val == WORD)
		return ("word");
	if (token_val == PIPE)
		return ("pipe");
	return (NULL);
}

void	print_tokens(t_lex *string)
{
	ft_fprintf(2, RED"---   Tokens Retrieved   ---\n"NUL);
	while (string)
	{
		ft_fprintf(2, "%s,		type: %s\n",
			string->word, token_value(string->type));
		string = string->next;
	}
	ft_putchar_fd('\n', 2);
}

void	print_commands(t_cmd *cmd)
{
	int	i;
	int	j;

	i = 0;
	ft_fprintf(2, RED"---   Commands Retrieved   ---\n"NUL);
	while (cmd)
	{
		ft_fprintf(2, "- COMMAND %d:\n", i + 1);
		j = 0;
		while (cmd && cmd->cmd[j])
		{
			ft_fprintf(2, "%s ", cmd->cmd[j]);
			j++;
		}
		ft_putchar_fd('\n', 2);
		i++;
		cmd = cmd->next;
	}
}

void	debug(t_lex *string, t_cmd *cmd)
{
	print_tokens(string);
	print_commands(cmd);
	ft_fprintf(2, RED"\n---   Output   ---\n"NUL);
}
