/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavila- <adavila-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 15:56:36 by adavila-          #+#    #+#             */
/*   Updated: 2024/08/16 15:56:36 by adavila-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*Print an error message with optional arguments
  given by 'format'*/
void	_error(const char *format, ...)
{
	va_list	args;

	va_start(args, format);
	ft_vfprintf(2, format, &args);
	va_end(args);
}

void	hdoc_warning(char *delimiter)
{
	char	*trim_del;

	trim_del = ft_strtrim(delimiter, " \n");
	_error(HDOC_WARN, trim_del);
	free(trim_del);
}

/*Check if 'path' is a directory or a file
  and throw error if its flag*/
int	file_type_error(char *path, int flag)
{
	struct stat	st;

	if (!path)
		return (0);
	if (stat(path, &st) < 0)
	{
		_error(ERRNO_ERROR, path, strerror(errno));
		return (127);
	}
	if (S_ISDIR(st.st_mode) && flag == IS_DIR)
	{
		_error(ERRNO_ERROR, path, strerror(EISDIR));
		return (126);
	}
	return (0);
}

/*Check whether the current 'cmd' is an absolute path.
  If not, check if 'cmd' is a valid command. */
int	bad_command_error(char *cmd)
{
	int	cmd_len;

	cmd_len = ft_strlen(cmd);
	if (!cmd_len)
		_error(BAD_CMD, "''");
	else
		_error(BAD_CMD, cmd);
	return (0);
}

void	_fatal(char	*msg)
{
	ft_putstr_fd("-minishell fatal error: ", 2);
	ft_putendl_fd(msg, 2);
	exit(EXIT_FAILURE);
}
