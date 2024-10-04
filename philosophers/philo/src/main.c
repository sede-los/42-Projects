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

	if (argc != 4 || argc != 5)
		return(write_error("Wrong number of arguments"));
	parse_checker(argv);
	if (init_all(&rules, argv))
		return (1);
	
}