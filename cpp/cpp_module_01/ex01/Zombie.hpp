/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 05:33:05 by sergio            #+#    #+#             */
/*   Updated: 2025/10/28 05:33:07 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX01_ZOMBIE_HPP
#define EX01_ZOMBIE_HPP

#include <iostream>

class Zombie
{
private:
	std::string name;
public:
	void announce();

	void SetName(const std::string &InputName);

	~Zombie();

};

Zombie *zombieHorde(int N, std::string name);


#endif
