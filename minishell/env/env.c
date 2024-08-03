/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-los <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 03:02:22 by sede-los          #+#    #+#             */
/*   Updated: 2024/08/03 03:02:26 by sede-los         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*get_env_value(char *value, char *env_str)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while(env_str && env_str[i] != '=')
		i++;
	i++;
	while(env_str && env_str[i])
	{
		value[j] = env_str[i];
		i++;
		j++;
	}
	value[j+1] = '\0';
	return (value);
}

int	env_init(t_mini *mini, char **env_array)
{
	t_env	*env;
	t_env	*new;
	int		i;

	if(!(env = malloc(sizeof(t_env))))
		return(1);
	env->str = ft_strdup(env_array[0]);
	env->next = NULL;
	mini->env = env;
	i = 1;
	while(env_array && env_array[0] && env_array[i])
	{
		if(!(new = malloc(sizeof(t_env))))
			return(1);
		new->str = ft_strdup(env_array[i]);
		new->next = NULL;
		env->next = new;
		env = new;
		i++;
	}
	return (0);
}