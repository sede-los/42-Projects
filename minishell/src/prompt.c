/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavila- <adavila-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 20:35:09 by adavila-          #+#    #+#             */
/*   Updated: 2024/07/26 20:35:09 by adavila-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	push_to_history(char *input)
{
	int			input_length;
	static char	*prev_input = NULL;

	input_length = ft_strlen(input);
	if (!input_length
		|| (prev_input && ft_strncmp(prev_input, input, input_length) == 0))
		return ;
	else
	{
		free(prev_input);
		prev_input = ft_strdup(input);
		add_history(input);
	}
}

/*Output the last name of a path*/
static char	*basename(void)
{
	char	*pwd;
	char	*last;

	pwd = getcwd(NULL, 0);
	if (!pwd)
		_fatal(BAD_MALLOC);
	last = ft_strrchr(pwd, '/') + 1;
	if (*last == '\0')
		last -= 1;
	last = ft_strdup(last);
	if (!last)
		_fatal(BAD_MALLOC);
	free (pwd);
	return (last);
}

/*Create the prompt that the user will see upon entry*/
char	*get_prompt(char **envp)
{
	char	*name;
	char	*usr;
	char	*current_dir;

	current_dir = basename();
	name = get_env_value("USER", envp);
	if (!name)
		usr = ft_strjoin("[ "GRN, "user");
	else if (ft_strncmp(name, "root", ft_strlen(name)) == 0)
		usr = ft_strjoin("[ "RED, name);
	else
		usr = ft_strjoin("[ "GRN, name);
	ft_strnapp(&usr, 7, "@minishell", NUL" ]",
		": ", BLU, current_dir, NUL, "> ");
	if (!usr)
		_fatal(BAD_MALLOC);
	free(current_dir);
	free(name);
	return (usr);
}
