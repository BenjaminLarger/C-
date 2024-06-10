/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 09:46:47 by blarger           #+#    #+#             */
/*   Updated: 2024/06/10 14:54:26 by blarger          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "DiamondTrap.hpp"

int	main()
{
	DiamondTrap    player("Doumbe");

    player.highFivesGuys();
    player.whoAmI();
	std::cout << player.ClapTrap::getName() << " has " << player.ClapTrap::getEnergyPoints() << " energy  points!" << std::endl;
    player.attack("Baki");
    std::cout << player.ClapTrap::getName() << " has " << player.ClapTrap::getEnergyPoints() << " energy  points!" << std::endl;
    player.attack("Baki");
    std::cout << player.ClapTrap::getName() << " has " << player.ClapTrap::getEnergyPoints() << " energy  points!" << std::endl;
    player.takeDamage(5);
    std::cout << player.ClapTrap::getName() << " has " << player.ClapTrap::getPoints() << " points of life!" << std::endl;
    player.beRepaired(1);
    player.takeDamage(7);
    std::cout << player.ClapTrap::getName() << " has " << player.ClapTrap::getPoints() << " points of life!" << std::endl;
    std::cout << player.ClapTrap::getName() << " has " << player.ClapTrap::getEnergyPoints() << " energy  points!" << std::endl;
}