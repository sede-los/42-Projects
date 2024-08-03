/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-los <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 23:52:52 by sede-los          #+#    #+#             */
/*   Updated: 2024/08/03 23:52:56 by sede-los         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	parse(t_mini *mini)
{
	//signal(SIGINT, &sig_int);
	//signal(SIGQUIT, &sig_quit);
	mini->ret ? ft_putstr_fd("❌ ", STDERR) : ft_putstr_fd("✅ ", STDERR);
	ft_putstr_fd("\033[0;32m\033[1mminishell ▸ \033[0m", STDERR);
}