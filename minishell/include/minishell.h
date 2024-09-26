/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavila- <adavila-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 20:27:08 by adavila-          #+#    #+#             */
/*   Updated: 2024/09/26 18:14:31 by sede-los         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "../libft/include/libft.h"
# include <readline/readline.h>
# include <readline/history.h>
# include <stdbool.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <errno.h>
# include <limits.h>
# include <sys/wait.h>
# include <signal.h>
# include "error.h"
# define EXIT -1
# define IN 0
# define OUT 1
# define LESS 0x0001
# define GREAT 0x002
# define DLESS 0x004
# define DGREAT 0x008
# define ROP_BITMASK 0x000F
# define PIPE 0x0010
# define WORD 0x0020
# define POPEN_MAX 1024
# define HDOC_PATH "./.minishell-hdoc_temp_"
# define RED "\001\e[1;31m\002"
# define NUL "\001\e[0m\002"
# define GRN "\001\e[1;32m\002"
# define BLU "\001\e[1;34m\002"

extern int				g_exit_code;
typedef struct s_lex	t_lex;
typedef struct s_cmd	t_cmd;
struct s_lex
{
	int		type;
	char	*word;
	t_lex	*next;
};

struct s_cmd
{
	int		heredoc_fd;
	char	**cmd;
	t_lex	*string;
	t_lex	*redirections;
	t_cmd	*next;
};

/*Debug only*/
void	debug(t_lex *string, t_cmd *cmd);

/*Error messages and handling*/
int		file_type_error(char *path, int flag);
int		bad_command_error(char *cmd);
void	_fatal(char	*msg);
void	_error(const char *format, ...);
void	hdoc_warning(char *delimiter);

/*t_cmd functionality*/
t_cmd	*new_cmd(t_lex *string);
void	add_cmd(t_cmd **head, t_cmd *node);
void	free_cmd(t_cmd *cmd);

/*t_lex functionality*/
t_lex	*new_lex(char *str, int type);
void	lex_remove(t_lex **to_delete, t_lex **prev, t_lex **head);
void	free_lex(t_lex *string);
void	lex_add(t_lex **head, t_lex *node);

/*Parsing and input checking*/
int		quote_check(char *str);
int		parse_input(t_lex **tokens, char *str);
int		syntax_check(t_lex *string);
void	remove_quotes(char *str);
int		parse_commands(t_cmd **command, t_lex *string, char **envp);

/*Command building*/
int		cmd_len(t_lex *string);
int		heredoc_seek(t_cmd *cmd, char **envp);
t_lex	*strip_redirections(t_lex **string);

/*Command execution*/
int		io_redirect(t_cmd *cmd, t_lex *rdir);
int		execute_pipeline(t_cmd *cmd, char ***envp);
char	*find_exec_path(t_cmd *cmd, char ***envp);
void	execute_command(t_cmd *cmd, pid_t pid, char ***envp);

/*Utils*/
int		is_operator(char c);
int		is_whitespace(int c);
int		is_dir(char *path);
int		is_absolute_path(char *cmd);
char	**dup_env(char **tab);
void	free_tab(char **tab);

/*Token clearing and expansion*/
int		expand_env(char *str, char **result, char **envp, bool leave_quoted);
int		expand_cmd(t_lex **string, char **envp);
int		expand_redirections(t_lex *redirections, char **envp);
void	expand_string(char **word, char **envp, bool leave_quoted);
int		get_string(char *str, char **result, bool leave_quoted);
int		get_qstring(char *str, char quote, char **result, char **envp);

/*Env manipulation*/
char	*get_env_value(char *str, char **envp);
char	*get_env_key(char *str);
char	*get_prompt(char **envp);
int		set_env_value(char *name, char *value, char **envp);
void	add_env_var(char *env, char *value, char ***envp);

/*Signals*/
void	handle_sigint(int sig);
void	handle_sigquit(int sig);

/*Builtins*/
int		ft_echo(char **args);
int		ft_pwd(void);
int		ft_cd(char **args, char ***envp);
int		ft_env(char **envp);
int		ft_export(char **args, char ***envp);
int		ft_unset(char **args, char ***envp);
int		ft_exit(char **args);
int		is_builtin(char *cmd);
int		exec_builtin(char **args, char ***envp, pid_t pid);
#endif // 
