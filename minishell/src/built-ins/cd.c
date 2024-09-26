/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavila- <adavila-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 19:23:51 by sede-los          #+#    #+#             */
/*   Updated: 2024/09/26 18:15:49 by sede-los         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	cd_error(char *key, int flag)
{
	if (flag == CD_UNSET_VAR)
		_error(CD_UNSET_ERROR, key);
	if (flag == CD_BAD_DIR)
		_error("-minishell: cd: %s: %s\n", key, strerror(errno));
	if (flag == CD_MULTIPLE_ARGS)
		_error(CD_ARGS_ERROR);
	return (1);
}

static int	update_wds(char *dir, char ***envp)
{
	int		status;
	char	*cwd;
	char	*prev_wd;

	prev_wd = getcwd(NULL, 0);
	if (!prev_wd)
		_fatal(BAD_MALLOC);
	if (set_env_value("OLDPWD", prev_wd, *envp) == 0)
		add_env_var("OLDPWD", prev_wd, envp);
	free(prev_wd);
	status = chdir(dir);
	if (status < 0)
		return (cd_error(dir, CD_BAD_DIR));
	cwd = getcwd(NULL, 0);
	if (!cwd)
		_fatal(BAD_MALLOC);
	if (set_env_value("PWD", cwd, *envp) == 0)
		add_env_var("PWD", cwd, envp);
	free(cwd);
	return (status);
}

/*Treat special cases such as "", -, or no parameters*/
int	go_to_path(char *key, char ***envp)
{
	int		status;
	char	*value;

	if (key[0] == '.')
		value = ft_strdup(".");
	else
		value = get_env_value(key, *envp);
	if (!value)
		return (cd_error(key, CD_UNSET_VAR));
	status = update_wds(value, envp);
	free(value);
	return (status);
}

int	ft_cd(char **args, char ***envp)
{
	int	ret;

	if (args[1] && args[2])
		return (cd_error(NULL, CD_MULTIPLE_ARGS));
	if (args[1] == NULL)
		ret = go_to_path("HOME", envp);
	else if (ft_strlen(args[1]) == 0)
		ret = go_to_path(".", envp);
	else if (ft_strncmp(args[1], "-", 1) == 0)
		ret = go_to_path("OLDPWD", envp);
	else
		ret = update_wds(args[1], envp);
	return (ret);
}
