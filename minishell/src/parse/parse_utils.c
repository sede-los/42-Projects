/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavila- <adavila-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 15:49:10 by adavila-          #+#    #+#             */
/*   Updated: 2024/08/16 15:49:10 by adavila-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*Check if the character corresponds to an operator*/
int	is_operator(char c)
{
	int			i;
	static char	tokens[4][2] = {{'<', LESS}, {'|', PIPE}, {'>', GREAT}, {0, 0}};

	i = 0;
	while (tokens[i][0])
	{
		if (tokens[i][0] == c)
			return (tokens[i][1]);
		i++;
	}
	return (0);
}

/*Returns 1 if we are at the end of the string
  or if it's an operator, 0 otherwise.*/
int	is_bad_token(t_lex *string)
{
	if (!string)
	{
		_error(SYNTAX_ERROR, "newline");
		return (1);
	}
	else if (is_operator(string->word[0]))
	{
		_error(SYNTAX_ERROR, string->word);
		return (1);
	}
	return (0);
}

/*Check for empty redirections or pipes*/
int	syntax_check(t_lex *string)
{
	t_lex		*prev;

	prev = NULL;
	while (string)
	{
		if ((ROP_BITMASK | string->type) == ROP_BITMASK)
			if (is_bad_token(string->next))
				return (0);
		if (string->type == PIPE && (string->next == NULL
				|| prev == NULL || string->next->type == PIPE))
		{
			_error(SYNTAX_ERROR, "|");
			return (0);
		}
		prev = string;
		string = string->next;
	}
	return (1);
}
