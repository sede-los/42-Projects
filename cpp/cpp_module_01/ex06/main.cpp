/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-los <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 02:50:34 by sede-los          #+#    #+#             */
/*   Updated: 2025/10/29 02:50:36 by sede-los         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv)
{
    Harl harl1;
    if (argc != 2)
        return(std::cout << "Usage: ./harlFilter level\n", 0);
    harl1.complain(argv[1]);
}