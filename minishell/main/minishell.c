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
	while(mini.exit == 0)
	{

	}
	free_env(mini.env);
	return (1);	
}
