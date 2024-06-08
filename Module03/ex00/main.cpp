/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 09:46:47 by blarger           #+#    #+#             */
/*   Updated: 2024/06/08 22:20:48 by blarger          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "ClapTrap.hpp"

int	main()
{
    ClapTrap    player("Doumbe");
    player.attack("Baki");
    std::cout << player.getName() << " has " << player.getEnergyPoints() << " energy  points!" << std::endl;
    player.attack("Baki");
    std::cout << player.getName() << " has " << player.getEnergyPoints() << " energy  points!" << std::endl;
    player.takeDamage(5);
    std::cout << player.getName() << " has " << player.getPoint() << " points of life!" << std::endl;
    player.beRepaired(1);
    player.takeDamage(7);
    std::cout << player.getName() << " has " << player.getPoint() << " points of life!" << std::endl;
    std::cout << player.getName() << " has " << player.getEnergyPoints() << " energy  points!" << std::endl;
}