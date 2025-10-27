/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 07:06:34 by sergio            #+#    #+#             */
/*   Updated: 2025/10/27 07:06:39 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int	main(int ac, char **av)
{
	int	i = 1;
	int	j = 0;

	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}
	while(i < ac)
	{
		while(av[i][j] != '\0')
		{
			std::cout << (char)std::toupper(av[i][j]);
			j++;
		}
		std::cout << " ";
		j = 0;
		i++;
	}
	std::cout << std::endl;
	return 0;
}
