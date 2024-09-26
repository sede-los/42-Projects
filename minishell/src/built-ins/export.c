/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavila- <adavila-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 02:08:00 by sede-los          #+#    #+#             */
/*   Updated: 2024/09/26 18:16:51 by sede-los         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	export_error(int error, char *arg)
{
	if (error == 0)
	{
		_error(EXP_INV_IDENT, arg);
		return (1);
	}
	return (0);
}

/*A valid env has to begin with a letter and has to be
  only alphanumeric*/
static int	env_valid_name(char *arg)
{
	int		i;

	i = 0;
	if (!ft_isalnum(arg[0]) || ft_isdigit(arg[0]))
		return (0);
	while (arg[i] && arg[i] != '=')
	{
		if (!ft_isalnum(arg[i]))
			return (0);
		i++;
	}
	return (1);
}

static char	*get_export_val(char *arg)
{
	char	*eq_sg;

	eq_sg = ft_strchr(arg, '=');
	if (eq_sg)
	{
		*eq_sg = '\0';
		return (eq_sg + 1);
	}
	else
		return (NULL);
}

/*Check if exported env already exists and if it's valid,
  otherwise, add it to env*/
static int	export_add(char **args, char ***envp)
{
	int		i;
	char	*name;
	char	*value;

	i = 1;
	while (args[i])
	{
		if (!env_valid_name(args[i]))
			return (export_error(0, args[i]));
		name = args[i];
		value = get_export_val(args[i]);
		if (!value)
		{
			i++;
			continue ;
		}
		if (set_env_value(name, value, *envp))
			return (0);
		add_env_var(name, value, envp);
		i++;
	}
	return (0);
}

int	ft_export(char **args, char ***envp)
{
	int	i;
	int	ret;

	i = 0;
	if (!args[1])
	{
		while ((*envp)[i])
		{
			printf("%s\n", (*envp)[i]);
			i++;
		}
	}
	else
		ret = export_add(args, envp);
	return (ret);
}
