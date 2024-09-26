/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavila- <adavila-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 19:43:02 by sede-los          #+#    #+#             */
/*   Updated: 2024/09/26 18:17:09 by sede-los         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*Only alphanumeric names, starting with a letter*/
static int	valid_unset(char *arg)
{
	int	i;

	i = 0;
	if (ft_isdigit(arg[0]))
		return (0);
	while (arg[i])
	{
		if (!ft_isalnum(arg[i]))
			return (0);
		i++;
	}
	return (1);
}

/*Since we only remove env vars here, keep the function static.
  Check env for an occurence of name in it. If found, free the 
  string and move every other env variable one place down.*/
static int	remove_env_var(char *name, char ***envp)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	len = ft_strlen(name);
	while ((*envp)[i])
	{
		if (ft_strncmp((*envp)[i], name, len) == 0)
		{
			free((*envp)[i]);
			j = i;
			while ((*envp)[j])
			{
				(*envp)[j] = (*envp)[j + 1];
				j++;
			}
			(*envp)[j] = NULL;
			return (0);
		}
		i++;
	}
	return (0);
}

int	ft_unset(char **args, char ***envp)
{
	int		i;
	int		ret;

	ret = 0;
	if (!args[1])
		return (0);
	i = 1;
	while (args[i])
	{
		if (valid_unset(args[i]))
			ret = remove_env_var(args[i], envp);
		i++;
	}
	return (ret);
}
