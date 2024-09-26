/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavila- <adavila-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 17:38:13 by adavila-          #+#    #+#             */
/*   Updated: 2024/09/26 18:14:59 by sede-los         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H
# define IS_REG 2
# define IS_DIR 1
# define EXIT_MANY_ARGS 0
# define EXIT_BADARGS 1
# define CD_UNSET_VAR 0
# define CD_BAD_DIR 1
# define CD_MULTIPLE_ARGS 2
# define CMD_NOT_FOUND 127
# define CD_UNSET_ERROR "-minishell: cd: %s not set\n"
# define CD_ARGS_ERROR "-minishell: cd: too many arguments\n"
# define EXIT_ARGS_ERROR "-minishell exit: too many arguments\n"
# define EXP_INV_IDENT	"-minishell: export: `%s': not a valid identifier\n"
# define EXIT_ALPHA_ERROR "-minishell: exit: %s: numeric argument required\n"
# define ERRNO_ERROR "-minishell: %s: %s\n"
# define BAD_QUOTES "-minishell: missing matching quote\n"
# define AMB_REDIR "-minishell: %s: ambiguous redirect\n"
# define HDOC_WARN "-minishell: warning: \
here-document delimited by EOF (wanted `%s')\n"
# define BAD_HDOC "heredoc: couldn't create temp file"
# define BAD_CMD "%s: command not found\n"
# define SYNTAX_ERROR "-minishell: syntax error near unexpected token `%s'\n"
# define DIR_ERROR "Is a directory"
# define NO_DIR_ERROR "Is not a directory"
# define BAD_GETCWD "error retrieving current directory"
# define BAD_MALLOC "malloc error during runtime: out of memory"
#endif
