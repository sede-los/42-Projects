/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 04:48:30 by sergio            #+#    #+#             */
/*   Updated: 2025/10/28 04:48:39 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	EX00_ZOMBIE_HPP
#define EX00_ZOMBIE_HPP

#include <iostream>

class Zombie
{
private:
	std::string name;
public:
	void	announce(void);
	Zombie(const std::string &inputname);
	~Zombie();
};

void	randomChump(std::string name);

Zombie	*newZombie(std::string name);

#endif
