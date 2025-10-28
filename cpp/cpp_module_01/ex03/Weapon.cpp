/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 07:22:13 by sergio            #+#    #+#             */
/*   Updated: 2025/10/28 07:22:15 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(const std::string &typeName)
{
	type = typeName;
}

const std::string &Weapon::getType() const
{
	return type;
}

void Weapon::setType(const std::string &typeName)
{
	type = typeName;
}