/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavila- <adavila-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 15:56:59 by adavila-          #+#    #+#             */
/*   Updated: 2024/09/26 18:19:39 by sede-los         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	open_file(int *io_fd, char *filename, int rdir_type)
{
	int		fd;
	int		fd_flags;

	fd_flags = O_RDONLY;
	if (rdir_type == DGREAT)
		fd_flags = O_CREAT | O_APPEND | O_RDWR;
	if (rdir_type == GREAT)
		fd_flags = O_CREAT | O_TRUNC | O_RDWR;
	fd = open(filename, fd_flags, 0644);
	if (fd < 0)
	{
		_error(ERRNO_ERROR, filename, strerror(errno));
		return (-1);
	}
	if (*io_fd != 1 && *io_fd != 0)
		close(*io_fd);
	*io_fd = fd;
	return (1);
}

/*Open all fds specfied in the prompt but keep only the 
  relevant ones.*/
int	io_redirect(t_cmd *cmd, t_lex *rdir)
{
	int	fd[2];
	int	status;

	status = 0;
	fd[IN] = STDIN_FILENO;
	fd[OUT] = STDOUT_FILENO;
	while (rdir)
	{
		if (rdir->type == DLESS)
			fd[IN] = cmd->heredoc_fd;
		if (rdir->type == LESS)
			status = open_file(&fd[IN], rdir->word, rdir->type);
		if (rdir->type == GREAT || rdir->type == DGREAT)
			status = open_file(&fd[OUT], rdir->word, rdir->type);
		if (status < 0)
			return (-1);
		rdir = rdir->next;
	}
	if (fd[IN] != 0 && dup2(fd[IN], STDIN_FILENO) > 0)
		close(fd[IN]);
	if (fd[OUT] != 1 && dup2(fd[OUT], STDOUT_FILENO) > 0)
		close(fd[OUT]);
	return (1);
}
