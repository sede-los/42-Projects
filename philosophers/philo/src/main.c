/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-los <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 05:09:36 by sede-los          #+#    #+#             */
/*   Updated: 2024/10/04 05:09:39 by sede-los         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	main(int argc, char	**argv)
{
	t_rules	rules;

	if (argc < 5 || argc > 6)
		return (write_error("Wrong number of arguments"));
	if (parse_checker(argv))
		return (1);
	if (init_all(&rules, argv))
		return (write_error("There was an error creating the threads"));
	if (launcher(&rules))
		return (1);
	return (0);
}
