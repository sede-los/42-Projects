/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavila- <adavila-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 15:50:15 by adavila-          #+#    #+#             */
/*   Updated: 2024/08/16 15:50:15 by adavila-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*Treat unquoted occurrences of $.*/
int	expand_env(char *str, char **result, char **envp, bool leave_quoted)
{
	int		key_length;
	char	*value;
	char	*key;

	key_length = 0;
	if ((*str == '\'' || *str == '\"')
		&& !leave_quoted)
		return (1);
	key = get_env_key(str);
	key_length = ft_strlen(key);
	value = get_env_value(key, envp);
	if (value)
		*result = ft_strapp(*result, value);
	free(key);
	free(value);
	return (key_length + 1);
}

/*Read an array of characters and expand every
  occurrence of quotes and $. Append the resulting
  expansion to a new array that will replace
  the original one upon completion. If leave_quoted 
  evaluates to true, it will expand without deleting quotes.
  If the resulting string is NULL and the expansion happened
  inside a quoted string, then return a NULL string ("")*/
void	expand_string(char **word, char **envp, bool leave_quoted)
{
	int		i;
	char	*result;
	char	*str;

	i = 0;
	str = *word;
	result = calloc(1, 1);
	if (!result)
		return ;
	while (str[i])
	{
		if (str[i] == '$')
			i += expand_env(&str[i + 1], &result, envp, leave_quoted);
		else if ((str[i] == '\'' || str[i] == '\"') && !leave_quoted)
			i += get_qstring(&str[i + 1], str[i], &result, envp);
		else
			i += get_string(&str[i], &result, leave_quoted);
	}
	if (!ft_strlen(result) && str[0] != '\'' && str[0] != '\"')
	{
		free(result);
		result = NULL;
	}
	free(*word);
	*word = result;
}

/*Expand every redirection token, if the redirection
  is a heredoc token do not expand. If the expanded
  character is an unquoted '$' and the result is null,
  print an error*/
int	expand_redirections(t_lex *redirections, char **envp)
{
	t_lex	*temp;
	char	*copy;

	copy = NULL;
	temp = redirections;
	while (temp)
	{
		if (temp->type != DLESS)
		{
			copy = ft_strdup(temp->word);
			expand_string(&temp->word, envp, false);
		}
		if (temp->word == NULL)
		{
			_error(AMB_REDIR, copy);
			free(copy);
			return (0);
		}
		free(copy);
		copy = NULL;
		temp = temp->next;
	}
	return (1);
}

/*Expand every word found in 'string' list after
  redirections have been stripped. If the expansion is NULL
  strip it from 'string'*/
int	expand_cmd(t_lex **string, char **envp)
{
	t_lex	*prev;
	t_lex	*temp;

	prev = NULL;
	temp = *string;
	while (temp)
	{
		expand_string(&temp->word, envp, false);
		if (temp->word == NULL)
		{
			lex_remove(&temp, &prev, string);
			continue ;
		}
		prev = temp;
		temp = temp->next;
	}
	return (1);
}
