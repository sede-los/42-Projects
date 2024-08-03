/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shlvl.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-los <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 03:42:03 by sede-los          #+#    #+#             */
/*   Updated: 2024/08/03 03:42:05 by sede-los         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	valid_value(char *val)
{
	int i;

	i = 0;
	while(val[i] == ' ' || val[i] == '\t' || val[i] == '\n'
		|| val[i] == '\r' || val[i] == '\v' || val[i] == '\f')
		i++;
	while(val[i])
	{
		if(!(ft_isdigit(val[i] - 48)))
			return (0);	
		i++;
	}
	return (1);
}

void	increment_shlvl(t_env *env)
{
	char	value[BUFF_SIZE];
	int		shlvl;
	char	*shlvl_new_value;
	
	get_env_value(value, env->str);
	if(!(valid_value(value)))
		return ;
	shlvl = ft_atoi(value);
	shlvl++;
	shlvl_new_value = ft_itoa(shlvl);
	while(env && env->next)
	{
		if(ft_strncmp("SHLVL", env->str, 5)== 0)
		{
			env->str = ft_strjoin("SHLVL", shlvl_new_value);
			return ;
		}
		env = env->next;
	}	
}