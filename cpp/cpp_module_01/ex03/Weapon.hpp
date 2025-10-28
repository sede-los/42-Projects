/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 07:17:07 by sergio            #+#    #+#             */
/*   Updated: 2025/10/28 07:17:09 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX03_WEAPON_HPP
#define EX03_WEAPON_HPP

#include <string>
#include <iostream>

class Weapon
{
private:
	std::string type;
public:
	explicit Weapon(const std::string &typeName);

	const std::string &getType() const;

	void setType(const std::string &typeName);
};


#endif