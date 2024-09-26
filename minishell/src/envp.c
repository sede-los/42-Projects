/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavila- <adavila-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 15:56:33 by adavila-          #+#    #+#             */
/*   Updated: 2024/08/16 15:56:33 by adavila-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*check_special(char *str)
{
	if (*str == '$')
		return (ft_strdup("0"));
	if (*str == '?')
		return (ft_itoa(g_exit_code));
	if (!*str)
		return (ft_strdup("$"));
	if (ft_strlen(str) == 1 && !ft_isalnum(*str))
		return (ft_strjoin("$", str));
	return (NULL);
}

int	set_env_value(char *env, char *value, char **envp)
{
	int		i;
	int		env_l;
	char	*new_str;

	i = 0;
	env_l = ft_strlen(env);
	new_str = ft_strjoin("", env);
	if (!new_str || !ft_strnapp(&new_str, 2, "=", value))
		_fatal(BAD_MALLOC);
	while (envp && envp[i])
	{
		if (ft_strncmp(envp[i], env, env_l) == 0 && *(envp[i] + env_l) == '=')
		{
			free(envp[i]);
			envp[i] = new_str;
			return (1);
		}
		i++;
	}
	free(new_str);
	return (0);
}

void	add_env_var(char *env_name, char *value, char ***envp)
{
	int		i;
	char	*new_var;
	char	**new_env;

	i = 0;
	while (*envp && (*envp)[i])
		i++;
	new_env = malloc(sizeof(char *) * (i + 2));
	new_var = ft_strjoin("", env_name);
	if (!new_env || !new_var || !ft_strnapp(&new_var, 2, "=", value))
		_fatal(BAD_MALLOC);
	i = 0;
	while (*envp && (*envp)[i])
	{
		new_env[i] = (*envp)[i];
		i++;
	}
	new_env[i] = new_var;
	new_env[i + 1] = NULL;
	free(*envp);
	*envp = new_env;
	return ;
}

char	*get_env_value(char *str, char **envp)
{
	int		i;
	int		key_length;
	char	*key;
	char	*special_chars;

	i = 0;
	special_chars = check_special(str);
	if (special_chars)
		return (special_chars);
	key = ft_strjoin(str, "=");
	if (!key)
		_fatal(BAD_MALLOC);
	key_length = ft_strlen(key);
	while (envp && envp[i])
	{
		if (ft_strncmp(envp[i], key, key_length) == 0)
		{
			free(key);
			return (ft_strdup(envp[i] + key_length));
		}
		i++;
	}
	free(key);
	return (NULL);
}

char	*get_env_key(char *str)
{
	int		i;
	char	*substr;

	i = 0;
	if (*str == '$' || *str == '?')
	{
		substr = ft_substr(str, 0, 1);
		if (!substr)
			_fatal(BAD_MALLOC);
		return (substr);
	}
	while (str[i] && ft_isalnum(str[i]))
		i++;
	substr = ft_substr(str, 0, i);
	if (!substr)
		_fatal(BAD_MALLOC);
	return (substr);
}
