/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavila- <adavila-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 17:46:41 by adavila-          #+#    #+#             */
/*   Updated: 2024/09/26 18:15:28 by sede-los         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*Handler for built-ins, if pid is 0, we are in the child process
  just exit after execution, otherwise, a simple command is taking
  place, return exit status of the built-in*/
int	exec_builtin(char **args, char ***envp, pid_t pid)
{
	int	exit_status;

	exit_status = 0;
	if (ft_strncmp(args[0], "echo", 4) == 0)
		exit_status = ft_echo(args);
	if (ft_strncmp(args[0], "pwd", 3) == 0)
		exit_status = ft_pwd();
	if (ft_strncmp(args[0], "cd", 2) == 0)
		exit_status = ft_cd(args, envp);
	if (ft_strncmp(args[0], "env", 3) == 0)
		exit_status = ft_env(*envp);
	if (ft_strncmp(args[0], "export", 6) == 0)
		exit_status = ft_export(args, envp);
	if (ft_strncmp(args[0], "exit", 4) == 0)
		exit_status = ft_exit(args);
	if (ft_strncmp(args[0], "unset", 5) == 0)
		exit_status = ft_unset(args, envp);
	if (pid == 0)
		exit(exit_status);
	return (exit_status);
}

int	is_builtin(char *cmd)
{
	int			i;
	static char	*builtins[]
		= {
		"echo", "cd", "pwd",
		"export", "unset", "env",
		"exit", NULL
	};

	i = 0;
	if (!cmd || cmd[0] == 0)
		return (0);
	while (builtins[i])
	{
		if (ft_strncmp(cmd, builtins[i], ft_strlen(builtins[i])) == 0)
			return (1);
		i++;
	}
	return (0);
}
