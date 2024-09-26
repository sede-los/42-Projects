/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavila- <adavila-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 15:57:03 by adavila-          #+#    #+#             */
/*   Updated: 2024/09/26 18:20:15 by sede-los         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*Make sure env has PWD and SHLVL*/
void	setup_env(char ***envp)
{
	char	*pwd;
	char	*shlvl;
	char	*new_shlvl;

	pwd = getcwd(NULL, 0);
	if (!pwd)
		_fatal(BAD_MALLOC);
	shlvl = get_env_value("SHLVL", *envp);
	new_shlvl = NULL;
	if (shlvl)
	{
		new_shlvl = ft_itoa(ft_atoi (shlvl) + 1);
		if (!new_shlvl)
			_fatal(BAD_MALLOC);
		set_env_value("SHLVL", new_shlvl, *envp);
	}
	else
		add_env_var("SHLVL", "1", envp);
	if (pwd && set_env_value("PWD", pwd, *envp) == 0)
		add_env_var("PWD", pwd, envp);
	free(new_shlvl);
	free (pwd);
	free (shlvl);
}

char	**dup_env(char **tab)
{
	int		i;
	char	**new_tab;

	i = 0;
	while (tab[i])
		i++;
	new_tab = malloc(sizeof(char *) * (i + 1));
	if (!new_tab)
		_fatal(BAD_MALLOC);
	i = 0;
	while (tab[i])
	{
		new_tab[i] = ft_strdup(tab[i]);
		if (!new_tab[i])
			_fatal(BAD_MALLOC);
		i++;
	}
	new_tab[i] = NULL;
	setup_env(&new_tab);
	return (new_tab);
}

int	is_whitespace(int c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

int	is_dir(char *path)
{
	struct stat	sb;

	return ((stat (path, &sb) == 0) && S_ISDIR (sb.st_mode));
}

int	is_absolute_path(char *cmd)
{
	while (cmd && *cmd)
	{
		if (*cmd == '/')
			return (1);
		cmd++;
	}
	return (0);
}
