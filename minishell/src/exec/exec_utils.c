/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavila- <adavila-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 15:53:22 by adavila-          #+#    #+#             */
/*   Updated: 2024/08/16 15:53:22 by adavila-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*Check if the given command exist in a bash(ish) way. First check
  for built-ins then check for PATH routes.*/
void	execute_command(t_cmd *cmd, pid_t pid, char ***envp)
{
	char	*path;

	if (cmd->cmd[0] == NULL)
		exit(EXIT_SUCCESS);
	if (is_builtin(cmd->cmd[0]))
		exec_builtin(cmd->cmd, envp, pid);
	path = find_exec_path(cmd, envp);
	if (path != NULL)
	{
		if (execve(path, cmd->cmd, *envp) < 0)
			_error("-minishell: %s: %s\n", path, strerror(errno));
		exit(126);
	}
	exit(CMD_NOT_FOUND);
}

static char	**get_path_directories(char **envp)
{
	int		i;
	char	**path_tab;

	i = 0;
	path_tab = NULL;
	while (envp && envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			path_tab = ft_split(envp[i] + 5, ':');
			break ;
		}
		i++;
	}
	return (path_tab);
}

static char	*find_executable(char *cmd, char **path_tab)
{
	int		i;
	char	*exec_path;

	i = 0;
	exec_path = NULL;
	if (!cmd || is_absolute_path(cmd))
		return (cmd);
	while (path_tab && path_tab[i])
	{
		exec_path = ft_strjoin(path_tab[i], "/");
		exec_path = ft_strapp(exec_path, cmd);
		if (access(exec_path, R_OK) == 0 && !is_dir(exec_path))
			return (exec_path);
		free(exec_path);
		i++;
	}
	return (NULL);
}

/*Check if the given command exists within PATH. If
  'exec_path' is not NULL, check if it is a directory
  or if it exists, if this check fails then print an
  error and exit, we won't even run the command*/
char	*find_exec_path(t_cmd *cmd, char ***envp)
{
	int		status;
	char	**path_tab;
	char	*exec_path;

	path_tab = get_path_directories(*envp);
	exec_path = find_executable(cmd->cmd[0], path_tab);
	free_tab(path_tab);
	if (!exec_path)
	{
		bad_command_error(cmd->cmd[0]);
		return (NULL);
	}
	status = file_type_error(exec_path, IS_DIR);
	if (status)
		exit(status);
	return (exec_path);
}
