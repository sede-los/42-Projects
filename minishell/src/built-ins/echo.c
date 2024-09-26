/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavila- <adavila-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 20:14:03 by sede-los          #+#    #+#             */
/*   Updated: 2024/09/26 18:16:08 by sede-los         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_echo(char **args)
{
	int		i;
	bool	newline;

	newline = true;
	i = 1;
	while (args && args[i] && (ft_strncmp(args[i], "-n", 2) == 0))
	{
		newline = false;
		i++;
	}
	while (args && args[i])
	{
		printf("%s", args[i]);
		if (args[i + 1])
			printf(" ");
		i++;
	}
	if (newline)
		printf("\n");
	return (0);
}
