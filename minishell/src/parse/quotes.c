/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavila- <adavila-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 15:49:35 by adavila-          #+#    #+#             */
/*   Updated: 2024/08/16 15:49:35 by adavila-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*Loop until a matching quote for 'quote_char'(if any)
 is found, and increment the number of occurrences on 'n_quote'.
 */
static int	match_quote(char *str, int *n_quote, char quote_char)
{
	int	i;

	i = 0;
	*n_quote += 1;
	while (str[i] && str[i] != quote_char)
		i++;
	if (str[i] == quote_char)
		*n_quote += 1;
	return (i + 1);
}

/*Check whether quotes are balanced or not.*/
int	quote_check(char *str)
{
	int	i;
	int	single_q;
	int	double_q;

	i = 0;
	single_q = 0;
	double_q = 0;
	while (str && str[i])
	{
		if (str[i] == '\"')
			i += match_quote(&str[i + 1], &double_q, '\"');
		if (str[i] == '\'')
			i += match_quote(&str[i + 1], &single_q, '\'');
		if (str[i])
			i++;
	}
	if ((single_q > 0 && single_q % 2 != 0)
		|| (double_q > 0 && double_q % 2 != 0))
		return (0);
	return (1);
}

/*Removes the quotes of a word according
 to matching quotes.*/
void	remove_quotes(char *str)
{
	int		i;
	char	c;
	char	*ptr;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '\"')
		{
			c = str[i];
			ft_memmove(&str[i], &str[i + 1], strlen(str) - i);
			ptr = ft_strchr(&str[i], c);
			i = ptr - &str[0];
			ft_memmove(&str[i], &str[i + 1], strlen(str) - i);
			continue ;
		}
		i++;
	}
}
