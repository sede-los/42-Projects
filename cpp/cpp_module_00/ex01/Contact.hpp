/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 07:48:36 by sergio            #+#    #+#             */
/*   Updated: 2025/10/27 07:48:39 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	EX01_CONTACT_H
#define	EX01_CONTACT_H

#include <iostream>

class Contact
{
private:
	std::string	FirstName;
	std::string	LastName;
	std::string	Nickname;
	std::string	PhoneNumber;
	std::string	DarkestSecret;
	bool		Initialized;
public:
	Contact() : Initialized(false) {};

	void		SetContact(std::string First, std::string Last, std::string Nick, std::string Phone, std::string Secret);
	void		PrintContact();
	int 		ContactExists();
	std::string	GetFirstName();
	std::string	GetLastName();
	std::string	GetNickname();
};

#endif