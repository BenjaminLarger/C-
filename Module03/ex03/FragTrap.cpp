/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 11:29:22 by blarger           #+#    #+#             */
/*   Updated: 2024/06/10 14:50:27 by blarger          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "FragTrap.hpp"

unsigned int	points = 100;
/* --------------CONSTRUCTORS */

FragTrap::FragTrap(std::string _name) :
	ClapTrap(_name, 100, 100, 30)
{
	std::cout << GREEN << "FragTrap constructor called passing "
	<< _name << " as name!" << std::endl;
}

FragTrap::FragTrap() :
	ClapTrap("Beni", 100, 100, 30)
{
		std::cout << GREEN << "FragTrap default constructor called!" << RESET << std::endl;
}

/* --------------DECONSTRUCTORS */

FragTrap::~FragTrap(void)
{
	std::cout << RED << "FragTrap deconstructor called. " << this->ClapTrap::getName() << " object destroyed!" << RESET << std::endl;
}

/* --------------COPY */
FragTrap::FragTrap(const FragTrap& other)
	: ClapTrap(other.ClapTrap::getName(), 100, 50, 20)
{
	std::cout << GREEN << "FragTrap calling copy assignment!" << RESET << std::endl;
};

/* --------------FUNCTIONS */

void	FragTrap::highFivesGuys(void)
{
	std::cout << YELLOW << "Wanna do a high five ?!" << RESET << std::endl;
}

/* GETTER */
unsigned int	FragTrap::getPoints(void) const { return (100); };
unsigned int	FragTrap::getAttackDamage(void) const { return (30);};
std::string		FragTrap::getName(void) const { return ("ben"); };
//unsigned int	FragTrap::getPoints(void) const { return (100); };
