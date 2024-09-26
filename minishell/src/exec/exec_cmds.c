/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavila- <adavila-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 15:53:37 by adavila-          #+#    #+#             */
/*   Updated: 2024/08/16 15:53:37 by adavila-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*Do pipe redirections to stdin/stdout, if we are at the last
  command, don't redirect the output.*/
static void	do_piping(int in, int out, void *next)
{
	if (in != STDIN_FILENO)
	{
		dup2(in, STDIN_FILENO);
		close(in);
	}
	if (out != STDOUT_FILENO)
	{
		if (next)
			dup2(out, STDOUT_FILENO);
		close(out);
	}
}

/*This will only happen if the parent is executing a built-in*/
static int	do_simple_cmd(t_cmd *cmd, char ***envp)
{
	int	old_stdin;
	int	old_stdout;

	old_stdin = dup(STDIN_FILENO);
	old_stdout = dup(STDOUT_FILENO);
	if (io_redirect(cmd, cmd->redirections) < 0)
	{
		close(old_stdin);
		close(old_stdout);
		g_exit_code = 1;
		return (1);
	}
	g_exit_code = exec_builtin(cmd->cmd, envp, 1);
	dup2(old_stdin, STDIN_FILENO);
	dup2(old_stdout, STDOUT_FILENO);
	close(old_stdin);
	close(old_stdout);
	return (0);
}

/*Create a subshell for every command. For every subshell do what 
  bash does:
  	1. Error checking for unknown and/or invalid commands.
	2. Pipe previous stdout (if any) to the current stdin.
	3. Pipe current command stdout to the next command. If there is 
	   no next command, redirect to stdout.
	4. Do all other redirects (<, <<...). Exit if any redirect is
	   invalid.
	5. Run the command.
*/
static int	spawn_proc(int *fds, t_cmd *cmd, char ***envp)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		do_piping(fds[IN], fds[OUT], cmd->next);
		if (io_redirect(cmd, cmd->redirections) < 0)
			exit(EXIT_FAILURE);
		execute_command(cmd, pid, envp);
	}
	if (fds[IN] != 0)
		close(fds[IN]);
	close(fds[OUT]);
	return (pid);
}

static int	exit_status(int *pid, int length, int fdin)
{
	int	i;
	int	status;

	i = 0;
	if (fdin)
		close(fdin);
	while (i < length)
	{
		waitpid(pid[i], &status, 0);
		i++;
	}
	if (WIFEXITED(status))
		g_exit_code = WEXITSTATUS(status);
	return (1);
}

/*Run all commands in a pipeline*/
int	execute_pipeline(t_cmd *cmd, char ***envp)
{
	int		i;
	int		p[2];
	int		fds[2];
	int		pid[256];

	if (is_builtin(cmd->cmd[0]) && !cmd->next)
		return (do_simple_cmd(cmd, envp));
	i = 0;
	fds[IN] = 0;
	while (cmd)
	{
		if (pipe(p) < 0)
			return (-1);
		fds[OUT] = p[1];
		pid[i] = spawn_proc(fds, cmd, envp);
		if (pid[i] < 0)
			return (-1);
		fds[IN] = p[IN];
		cmd = cmd->next;
		i++;
	}
	exit_status(pid, i, fds[IN]);
	return (1);
}
