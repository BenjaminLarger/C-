/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 11:29:22 by blarger           #+#    #+#             */
/*   Updated: 2024/06/09 11:36:31 by blarger          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "FragTrap.hpp"

/* --------------CONSTRUCTORS */

FragTrap::FragTrap(std::string _name) :
	ClapTrap(_name, 100, 100, 30)
{
	std::cout << GREEN << "FragTrap constructor called passing "
	<< _name << " as name!" << std::endl;
}

FragTrap::FragTrap() :
	ClapTrap("benji", 100, 100, 30)
{
		std::cout << GREEN << "FragTrap default constructor setting default name <ben>!" << RESET << std::endl;
}

/* --------------DECONSTRUCTORS */

FragTrap::~FragTrap(void)
{
	std::cout << RED << "FragTrap deconstructor called. " << this->getName() << " object destroyed!" << RESET << std::endl;
}

/* --------------COPY */
FragTrap::FragTrap(const FragTrap& other)
	: ClapTrap(other.getName(), 100, 50, 20)
{
	std::cout << GREEN << "FragTrap calling copy assignment!" << RESET << std::endl;
};

/* --------------FUNCTIONS */

void	FragTrap::highFivesGuys(void)
{
	std::cout << YELLOW << "Wanna do a high five ?!" << RESET << std::endl;
}