/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-los <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 01:00:14 by sede-los          #+#    #+#             */
/*   Updated: 2025/10/29 01:00:16 by sede-los         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPP01_HARL_HPP
#define CPP01_HARL_HPP

#include <string>
#include <iostream>
#include <cstdlib>

class Harl
{
private:
void	debug(void);
	void	info(void);
	void	warning(void);
	void	error(void);

public:
	void	complain(char	*str);
};

#endif
