/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-los <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 02:00:44 by sede-los          #+#    #+#             */
/*   Updated: 2024/08/03 02:00:51 by sede-los         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
#	define MINISHELL_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <dirent.h>
# include <sys/wait.h>
# include <limits.h>
# include <errno.h>
# include <signal.h>

#	define BUFF_SIZE 4096
#	define STDIN 0
#	define STDOUT 1
#	define STDERR 2

typedef struct	s_token
{
	char			*str;
	int				type;
	struct s_token	*prev;
	struct s_token	*next;
}				t_token;

typedef struct	s_env
{
	char	*str;
	struct s_env *next;
}				t_env;

typedef struct	s_mini
{
	t_token	*token;
	t_env	*env;
	int		in;
	int		out;
	int		fdin;
	int		fdout;
	int		pipin;
	int		pipout;
	int		pid;
	int		exit;
}				t_mini;

void	reset_fds(t_mini *mini);
int		env_init(t_mini *mini, char **env_array);
void	increment_shlvl(t_env *env);
int		valid_value(char *val);
char	*get_env_value(char *value, char *env_str);
void	free_env(t_env *env);

#endif