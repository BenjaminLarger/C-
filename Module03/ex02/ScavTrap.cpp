/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 09:26:13 by blarger           #+#    #+#             */
/*   Updated: 2024/06/09 11:25:26 by blarger          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "ScavTrap.hpp"

/* --------------CONSTRUCTORS */

ScavTrap::ScavTrap(std::string _name) :
	ClapTrap(_name, 100, 50, 20)
{
	std::cout << GREEN << "ScavTrap constructor called passing "
	<< _name << " as name!" << std::endl;
}

ScavTrap::ScavTrap() :
	ClapTrap("benji", 100, 50, 20)
{
		std::cout << GREEN << "ScavTrap default constructor setting default name <ben>!" << RESET << std::endl;
}

/* --------------DECONSTRUCTORS */

ScavTrap::~ScavTrap(void)
{
	std::cout << RED << "ScavTrap deconstructor called. " << this->getName() << " object destroyed!" << RESET << std::endl;
}

/* --------------COPY */
ScavTrap::ScavTrap(const ScavTrap& other)
	: ClapTrap(other.getName(), 100, 50, 20)
{
	std::cout << GREEN << "ScavTrap calling copy assignment!" << RESET << std::endl;
};

/* --------------FUNCTIONS */

void	ScavTrap::guardGate(void)
{
	std::cout << CYAN << "ScavTrap is now in Gate keeper mode!" << RESET << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (this->getEnergyPoints() >= 1)
	{
		this->setEnergyPoints(this->getEnergyPoints() - 1);
		std::cout << MAGENTA << "ScavTrap " << this->getName() << " attacks " << target << ", causing " << this->getAttackDamage() << " points of damage!" << RESET << std::endl;
	}
	else
		std::cout << ORANGE << "Not enough energy points to attack!" << RESET << std::endl;
}