/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavila- <adavila-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 15:56:43 by adavila-          #+#    #+#             */
/*   Updated: 2024/09/26 18:19:29 by sede-los         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*get_temp_name(void)
{
	char		*temp_name;
	char		*index_str;
	static int	temp_index = 1;

	index_str = ft_itoa(temp_index);
	if (!index_str)
		_fatal(BAD_MALLOC);
	temp_name = ft_strjoin(HDOC_PATH, index_str);
	free(index_str);
	if (!temp_name)
		_fatal(BAD_MALLOC);
	temp_index++;
	return (temp_name);
}

static int	read_into_fd(int fd, char *del, bool is_quoted, char **envp)
{
	char	*line;

	line = NULL;
	while (1)
	{
		write(1, "> ", 2);
		line = get_next_line(0);
		if (!line)
		{
			hdoc_warning(del);
			break ;
		}
		if (ft_strncmp(line, del, ft_strlen(line)) == 0)
			break ;
		if (!is_quoted)
			expand_string(&line, envp, true);
		ft_putstr_fd(line, fd);
		free(line);
	}
	free(line);
	return (1);
}

static int	create_temp_file(char *del, bool is_quoted, char **envp)
{
	int		fd;
	char	*temp_name;

	temp_name = get_temp_name();
	fd = open(temp_name, O_CREAT | O_TRUNC | O_RDWR, 0644);
	if (fd < 0 || !read_into_fd(fd, del, is_quoted, envp))
	{
		unlink(temp_name);
		free(temp_name);
		return (-1);
	}
	close(fd);
	fd = open(temp_name, O_RDONLY, 0644);
	unlink(temp_name);
	free(temp_name);
	if (fd < 0)
		return (-1);
	return (fd);
}

/*Wrapper function for heredoc functionality*/
static int	heredoc(char *del, char **envp)
{
	int		fd;
	char	*escape_del;
	bool	is_quoted;

	if (del[0] == '\'' || del[0] == '\"')
	{
		is_quoted = true;
		remove_quotes(del);
	}
	else
		is_quoted = false;
	escape_del = ft_strdup(del);
	if (!escape_del || !ft_strnapp(&escape_del, 1, "\n"))
		_fatal(BAD_MALLOC);
	fd = create_temp_file(escape_del, is_quoted, envp);
	free(escape_del);
	if (fd < 0)
	{
		_error(BAD_HDOC);
		return (-1);
	}
	return (fd);
}

/*Parse all heredocs before any redirection or piping.
 From The Open Group Base in 2.3 Token Recognition:
 	"When an io_here token has been recognized by the grammar 
 	(see Shell Grammar), one or more of the subsequent lines 
 	immediately following the next NEWLINE token form the 
 	body of one or more here-documents and shall be parsed
 	according to the rules of Here-Document".*/
int	heredoc_seek(t_cmd *cmd, char **envp)
{
	t_lex	*temp;

	temp = cmd->redirections;
	while (temp)
	{
		if (temp->type == DLESS)
		{
			if (cmd->heredoc_fd > 0)
				close(cmd->heredoc_fd);
			cmd->heredoc_fd = heredoc(temp->word, envp);
			if (cmd->heredoc_fd < 0)
				return (-1);
		}
		temp = temp->next;
	}
	return (1);
}
