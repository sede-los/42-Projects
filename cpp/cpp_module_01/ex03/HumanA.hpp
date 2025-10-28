/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 07:35:17 by sergio            #+#    #+#             */
/*   Updated: 2025/10/28 07:35:19 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX03_HUMANA_HPP
#define EX03_HUMANA_HPP

#include "Weapon.hpp"
#include <string>

class HumanA {
private:
	Weapon &_weapon;
	std::string _name;

public:
	HumanA(std::string TypeName, Weapon &TypeWeapon);

	void attack();
};

#endif
