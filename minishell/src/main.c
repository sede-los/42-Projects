/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavila- <adavila-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 20:33:09 by adavila-          #+#    #+#             */
/*   Updated: 2024/09/26 18:17:59 by sede-los         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*Wrapper for all minishell functionality, a return
  value of -1 signals the terminal to exit*/
static int	minishell(char **input, char ***envp, bool d_mode)
{
	char	*aux;
	t_lex	*tokens;
	t_cmd	*command;

	aux = *input;
	tokens = NULL;
	command = NULL;
	if (!(*input))
		return (EXIT);
	*input = ft_strtrim(*input, " \t");
	free(aux);
	if (!parse_input(&tokens, *input)
		|| !parse_commands(&command, tokens, *envp))
		return (0);
	if (d_mode)
		debug(tokens, command);
	execute_pipeline(command, envp);
	free_lex(tokens);
	free_cmd(command);
	return (1);
}

static bool	set_debug(char **argv)
{
	if (argv[1] == NULL)
		return (false);
	if (argv[1] && argv[2])
	{
		_error("minishell: too many arguments\n");
		exit(EXIT_FAILURE);
	}
	if (ft_strncmp(argv[1], "--debug", ft_strlen(argv[1])) == 0)
		return (true);
	else
	{
		_error("minishell: invalid option \"%s\"\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	return (false);
}

int	g_exit_code = 0;

int	main(int argc, char **argv, char **envp)
{
	bool	debug;
	char	*prompt;
	char	*input;
	char	**new_env;

	new_env = dup_env(envp);
	signal(SIGINT, handle_sigint);
	signal(SIGQUIT, handle_sigquit);
	debug = set_debug(argv);
	while (argc && argv)
	{
		prompt = get_prompt(new_env);
		input = readline(prompt);
		if (minishell(&input, &new_env, debug) == EXIT)
			exit(EXIT_SUCCESS);
		free(prompt);
		free(input);
	}
}
