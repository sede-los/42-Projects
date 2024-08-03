/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-los <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 02:24:56 by sede-los          #+#    #+#             */
/*   Updated: 2024/08/03 02:24:59 by sede-los         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_mini mini;

	(void)argc;
	(void)argv;
	mini.in = dup(STDIN);
	mini.out = dup(STDOUT);
	mini.exit = 0;
	reset_fds(&mini);
	env_init(&mini, envp);
	increment_shlvl(mini.env);
	//pruebas
	int i = 1;
	t_env *env = mini.env;
	while(env)
	{
		printf("variable de entorno numero %d : %s\n", i, env->str);
		i++;
		env = env->next;
	}
	//fin de pruebas
	free_env(mini.env);
	return (1);	
}
