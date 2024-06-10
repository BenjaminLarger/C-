/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 11:47:47 by blarger           #+#    #+#             */
/*   Updated: 2024/06/10 15:07:14 by blarger          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "ClapTrap.hpp"

/* --------------CONSTRUCTORS */

ClapTrap::ClapTrap(std::string _name) : name(_name), points(10), energyPoints(10), attackDamage(0)
{
	std::cout << GREEN << "ClapTrap constructor setting " << _name << " as name, " << points << " as points, " << energyPoints << " as energy points, " << attackDamage << " as attack damage !" << RESET << std::endl;

}

ClapTrap::ClapTrap() : name("Ben"), points(10), energyPoints(10), attackDamage(0)
{
		std::cout << GREEN << "ClapTrap default constructor setting default name <ben>!" << RESET << std::endl;
}

ClapTrap::ClapTrap(std::string _name, unsigned int _points, unsigned int _energyPoints, unsigned int _attackDamage)
	: name(_name),
	points(_points),
	energyPoints(_energyPoints),
	attackDamage(_attackDamage)
{
	std::cout << GREEN << "ClapTrap constructor setting " << _name << " as name, " << points << " as points, " << energyPoints << " as energy points, " << attackDamage << " as attack damage !" << RESET << std::endl;
}

/* --------------DECONSTRUCTORS */

ClapTrap::~ClapTrap(void)
{
	std::cout << RED << "ClapTrap deconstructor called. " << this->name << " object destroyed!" << RESET << std::endl;
}

/* --------------COPY */
ClapTrap::ClapTrap(const ClapTrap& other) : name(other.name), points(other.points), energyPoints(other.energyPoints), attackDamage(other.attackDamage)
{
	std::cout << GREEN << "ScavTrap calling copy assignment!" << RESET << std::endl;
};


/* --------------FUNCTIONS */
void	ClapTrap::attack(const std::string& target)
{
	if (this->energyPoints >= 1)
	{
		this->energyPoints--;
		std::cout << CYAN << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << RESET << std::endl;
	}
	else
		std::cout << ORANGE << "Not enough energy points to attack!" << RESET << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->points > amount)
	{
		std::cout << CYAN << "ClapTrap " << name << ", taking " << amount << " points of damage!" << RESET << std::endl;
		this->points -= amount;
	}
	else
	{
		std::cout << CYAN << "ClapTrap " << name << ", taking " << this->points << " points of damage!" << RESET << std::endl;
		this->points = 0;
		std::cout << ORANGE <<  this->name << " has died!" << RESET << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->energyPoints >= 1)
	{
		this->points += amount;
		this->energyPoints--;
		std::cout << CYAN << "ClapTrap " << name << ", repairing " << amount << " points!" << RESET << std::endl;
	}
	else
		std::cout << ORANGE << "Not enough energy points to get repaired!" << RESET << std::endl;
}


/* GETTER */
std::string		ClapTrap::getName(void) const { return (this->name); };
unsigned int	ClapTrap::getPoints(void) const { return (this->points); };
unsigned int	ClapTrap::getEnergyPoints(void) const { return (this->energyPoints); };
unsigned int	ClapTrap::getAttackDamage(void) const { return (this->attackDamage);};

/* SETTER */
void			ClapTrap::setEnergyPoints(unsigned int new_points) {this->energyPoints = new_points;}