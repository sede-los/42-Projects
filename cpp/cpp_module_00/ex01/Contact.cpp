/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 08:10:50 by sergio            #+#    #+#             */
/*   Updated: 2025/10/27 08:10:52 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void	Contact::SetContact(std::string First, std::string Last, std::string Nick, std::string Phone, std::string Secret)
{
	FirstName = First;
	LastName = Last;
	Nickname = Nick;
	PhoneNumber = Phone;
	DarkestSecret = Secret;
	Initialized = true;
}

void	Contact::PrintContact()
{
	std::cout << (FirstName + "\n" + LastName + "\n" + Nickname + "\n" + PhoneNumber + "\n" + DarkestSecret + "\n");
}

int	Contact::ContactExists()
{
	return (Initialized);
}

std::string	Contact::GetFirstName()
{
	return (FirstName);
}

std::string	Contact::GetLastName()
{
	return (LastName);
}

std::string	Contact::GetNickname()
{
	return (Nickname);
}