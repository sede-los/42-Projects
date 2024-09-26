/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavila- <adavila-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 21:08:27 by adavila-          #+#    #+#             */
/*   Updated: 2024/07/26 21:08:27 by adavila-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*Returns the length inside the quotes delimited by 'quote',
  quotes are included in the total length.*/
static int	get_qword(char *str, char quote)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != quote)
		i++;
	i++;
	return (i + 1);
}

/*Extract the length of a 'word' according to Shell's definitions
  and push it into the linked list.
  Nested quoted words, if any, shall be added to the length of the word
  (e.g. foo"bar baz" is considered a word, while 'foo' 'bar' are two
  words).*/
static int	get_word(char *str, t_lex **string)
{
	int	i;

	i = 0;
	while (str[i] && !is_whitespace(str[i]) && !is_operator(str[i]))
	{
		if ((str[i] == '\'' || str[i] == '\"'))
			i += get_qword(&str[i + 1], str[i]);
		else
			i++;
	}
	if (i)
		lex_add(string, new_lex(ft_substr(str, 0, i), WORD));
	return (i);
}

/*An operator has been found, check whether is simple (e.g. '<')
  or double (e.g. '<<') and push it into the token list. Returns
  the length of the whole operator.*/
static int	get_operator(char *str, t_lex **string)
{
	int	operator;

	operator = is_operator(*str);
	if (*str == '>' && *(str + 1) == '>')
	{
		lex_add(string, new_lex(ft_substr(str, 0, 2), DGREAT));
		return (2);
	}
	else if (*str == '<' && *(str + 1) == '<')
	{
		lex_add(string, new_lex(ft_substr(str, 0, 2), DLESS));
		return (2);
	}
	else if (operator)
	{
		lex_add(string, new_lex(ft_substr(str, 0, 1), operator));
		return (1);
	}
	return (0);
}

/*Split string into tokens according to Shell Grammar Rules.
  The separator used for token delimitation is <space> / 
  <operator>.*/
static int	get_tokens(char *str, t_lex **string)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (is_operator(str[i]))
			i += get_operator(&str[i], string);
		if (is_whitespace(str[i]))
			i++;
		else
			i += get_word(&str[i], string);
	}
	return (1);
}

/*Convert the string read into a linked list of tokens.
  On success returns 1, otherwise 0. If str is longer than
  0, add it into the terminal.*/
int	parse_input(t_lex **tokens, char *str)
{
	if (ft_strlen(str) == 0)
		return (0);
	add_history(str);
	if (quote_check(str))
		get_tokens(str, tokens);
	else
	{
		_error(BAD_QUOTES);
		g_exit_code = 2;
		return (0);
	}
	if (!syntax_check(*tokens))
	{
		free_lex(*tokens);
		g_exit_code = 2;
		return (0);
	}
	return (1);
}
