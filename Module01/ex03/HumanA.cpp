/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 09:32:59 by blarger           #+#    #+#             */
/*   Updated: 2024/06/01 16:20:52 by blarger          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "HumanA.hpp"

void	HumanA::attack(void)
{
	std::cout << name << ATTACK << weapon.getType() << std::endl;
}

/* void	HumanA::setWeapon(Weapon _weapon)
{
	this->weapon = _weapon;
	return ;
} */

/* CONSTRUCTOR */
HumanA::HumanA(const std::string _name, Weapon& _weapon) : name(_name), weapon(_weapon)
{
	std::cout << GREEN << "Human A born." << RESET << std::endl;
}
/* DECONSTRUCTOR */
HumanA::~HumanA(void)
{
	std::cout << RED << "Human A died." << RESET << std::endl;
	return ;
}