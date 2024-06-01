/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 09:33:11 by blarger           #+#    #+#             */
/*   Updated: 2024/06/01 19:30:49 by blarger          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "HumanB.hpp"

void	HumanB::setWeapon(Weapon &_weapon)
{
	this->weapon = &_weapon;
}

void	HumanB::attack(void)
{
	std::cout << name << ATTACK << weapon->getType() << std::endl;
}


/* CONSTRUCTOR */
HumanB::HumanB(const std::string& _name) : name(_name), weapon(NULL)
{
	std::cout << GREEN << "Human B born." << RESET << std::endl;
	return ;
}
/* DECONSTRUCTOR */
HumanB::~HumanB(void)
{
	std::cout << RED << "Human B died" << RESET << std::endl;
	return ;
}