/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavila- <adavila-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 15:50:42 by adavila-          #+#    #+#             */
/*   Updated: 2024/08/16 15:50:42 by adavila-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*Append a simple word to the resulting string*/
int	get_string(char *str, char **result, bool leave_quoted)
{
	int		i;
	char	*string;

	i = 0;
	while (str[i] && str[i] != '$')
	{
		if ((str[i] == '\'' || str[i] == '\"') && !leave_quoted)
			break ;
		i++;
	}
	string = ft_substr(str, 0, i);
	if (i && string)
		*result = ft_strapp(*result, string);
	free(string);
	return (i);
}

/*Append the words inside the simple/double quotes
  to the final string. Do any expansions if needed.*/
int	get_qstring(char *str, char quote, char **result, char **envp)
{
	int		i;
	char	*remainder;
	bool	sq_status;

	i = 0;
	if (quote == '\'')
		sq_status = true;
	while (str[i] && str[i] != quote)
		i++;
	remainder = ft_substr(str, 0, i);
	if (!sq_status)
		expand_string(&remainder, envp, true);
	if (!remainder)
		remainder = ft_strdup("\0");
	if (!remainder)
		_fatal(BAD_MALLOC);
	ft_strnapp(result, 1, remainder);
	free(remainder);
	return (i + 2);
}
