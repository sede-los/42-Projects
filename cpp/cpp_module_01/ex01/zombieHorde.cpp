/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 05:41:02 by sergio            #+#    #+#             */
/*   Updated: 2025/10/28 05:41:05 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name)
{
	Zombie	*zombieArray;
	zombieArray = new Zombie[N];
	for	(int i = 0; i < N; i++)
		zombieArray[i].SetName(name);
	return	zombieArray;
}
