/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 09:46:47 by blarger           #+#    #+#             */
/*   Updated: 2024/06/09 10:38:11 by blarger          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "ScavTrap.hpp"

int	main()
{
    ScavTrap    player("Doumbe");
    player.guardGate();
    player.attack("Baki");
    std::cout << player.getName() << " has " << player.getEnergyPoints() << " energy  points!" << std::endl;
    player.attack("Baki");
    std::cout << player.getName() << " has " << player.getEnergyPoints() << " energy  points!" << std::endl;
    player.takeDamage(5);
    std::cout << player.getName() << " has " << player.getPoints() << " points of life!" << std::endl;
    player.beRepaired(1);
    player.takeDamage(7);
    std::cout << player.getName() << " has " << player.getPoints() << " points of life!" << std::endl;
    std::cout << player.getName() << " has " << player.getEnergyPoints() << " energy  points!" << std::endl;
}