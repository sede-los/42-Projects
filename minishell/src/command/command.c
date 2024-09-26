/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavila- <adavila-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 17:57:14 by adavila-          #+#    #+#             */
/*   Updated: 2024/09/26 18:18:46 by sede-los         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*Create an array of pointers to strings.*/
static char	**build_tab(t_lex *string)
{
	int		i;
	int		len;
	char	**tab;

	i = 0;
	len = cmd_len(string);
	tab = malloc(sizeof(char *) * (len + 1));
	if (!tab)
		return (NULL);
	while (i < len)
	{
		tab[i] = ft_strdup(string->word);
		string = string->next;
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

/*Read the list till a pipe operator is found
  or until the end of the list is found, while
  reading, duplicate each node and push it into 
  the new linked list.*/
static t_lex	*build_string(t_lex *string)
{
	t_lex	*new_str;
	t_lex	*node;
	char	*new_word;

	new_str = NULL;
	while (string && string->type != PIPE)
	{
		new_word = ft_strdup(string->word);
		if (!new_word)
			_fatal(BAD_MALLOC);
		node = new_lex(new_word, string->type);
		if (!node)
			_fatal(BAD_MALLOC);
		lex_add(&new_str, node);
		string = string->next;
	}
	return (new_str);
}

/*Populate with tokens from 'string'.
  On sucess, 'command' contains a list with
  a command and its arguments, a list with redirections
  and a pointer to the next command, if any.*/
static int	build_cmds(t_cmd **command, t_lex *string)
{
	t_lex	*temp;
	t_lex	*node;

	if (!string)
		return (-1);
	temp = string;
	while (temp)
	{
		if (temp->type == PIPE || temp->next == NULL)
		{
			node = build_string(string);
			add_cmd(command, new_cmd(node));
			string = temp->next;
		}
		temp = temp->next;
	}
	return (1);
}

/*Remove all redirections, expand the remaining string and construct
  the command table. If there is any here document, parse it before continuing*/
static int	construct_commands(t_cmd **command, t_lex *string, char **envp)
{
	t_cmd	*cmd_temp;

	if (!build_cmds(command, string))
		_fatal(BAD_MALLOC);
	cmd_temp = *command;
	while (cmd_temp)
	{
		cmd_temp->redirections = strip_redirections(&cmd_temp->string);
		expand_cmd(&(cmd_temp->string), envp);
		if (!expand_redirections(cmd_temp->redirections, envp))
			return (0);
		cmd_temp->cmd = build_tab(cmd_temp->string);
		if (heredoc_seek(cmd_temp, envp) < 0)
			return (0);
		cmd_temp = cmd_temp->next;
	}
	return (1);
}

/*Wrapper function for command construction and expansion*/
int	parse_commands(t_cmd **command, t_lex *string, char **envp)
{
	if (construct_commands(command, string, envp) == 0)
	{
		free_lex(string);
		free_cmd(*command);
		return (0);
	}
	return (1);
}
