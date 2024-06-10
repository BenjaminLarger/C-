/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 11:43:17 by blarger           #+#    #+#             */
/*   Updated: 2024/06/10 14:59:34 by blarger          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "DiamondTrap.hpp"

/* --------------CONSTRUCTORS */

DiamondTrap::DiamondTrap(std::string _name) :
	ClapTrap(_name,
	FragTrap::getPoints(),
	ScavTrap::getEnergyPoints(),
	FragTrap::getAttackDamage())	
{
	//DiamondTrap	copy(*this);
	this->name = _name;
}

std::string concatenateStrings(const std::string& str1, const std::string& str2) {
	return str1 + str2;
}

DiamondTrap::DiamondTrap() :
	ClapTrap(concatenateStrings(FragTrap::getName(), "_clap_name"),
	FragTrap::getPoints(),
	ScavTrap::getEnergyPoints(),
	FragTrap::getAttackDamage())
{
	this->name = concatenateStrings(FragTrap::getName(), "_clap_name");
	std::cout << GREEN << "DiamondTrap default constructor setting default name "
	<< this->name << "!" << RESET << std::endl;
}

/* --------------DECONSTRUCTORS */
DiamondTrap::~DiamondTrap(void)
{
	std::cout << RED << "DiamondTrap deconstructor called!" << RESET << std::endl;
}

/* --------------COPY */
DiamondTrap::DiamondTrap(const DiamondTrap& other)
    : ClapTrap(other.ScavTrap::getName(), 100, 50, 20), ScavTrap(other), FragTrap(other)
{
    std::cout << GREEN << "DiamondTrap calling copy assignment!" << RESET << std::endl;
}

/* --------------FUNCTIONS */
void	DiamondTrap::whoAmI(void)
{
	std::cout << YELLOW << "Who am I ?! => DiamondTrap name = " << this->name << " ClapTrap name = " << ClapTrap::getName() << RESET << std::endl;
}

void			DiamondTrap::attack(const std::string &target) { ScavTrap::attack(target);}
std::string		DiamondTrap::getName(void) const { return (this->name); };
