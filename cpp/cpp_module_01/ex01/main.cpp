/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 05:46:01 by sergio            #+#    #+#             */
/*   Updated: 2025/10/28 05:46:03 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	int n = 7;
	Zombie *ZombieHorde1 = zombieHorde(n, "Zombie");
	for(int i = 0; i < n; i++)
		ZombieHorde1[i].announce();
	delete[] ZombieHorde1;
}