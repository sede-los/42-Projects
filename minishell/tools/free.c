/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-los <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 07:09:44 by sede-los          #+#    #+#             */
/*   Updated: 2024/08/03 07:09:47 by sede-los         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	free_env(t_env *env)
{
	t_env *tmp;

	while(env && env->next)
	{
		tmp = env;
		env = env->next;
		ft_memdel(tmp->str);
		ft_memdel(tmp);
	}
	ft_memdel(env->str);
	ft_memdel(env);
}
