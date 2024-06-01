/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 09:32:47 by blarger           #+#    #+#             */
/*   Updated: 2024/06/01 19:31:02 by blarger          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Weapon.hpp"

const std::string Weapon::getType(void)
{
	return (this->type);
}

void Weapon::setType(/* const  */std::string _type)
{
	this->type = _type;
}
/* CONSTRUCTOR */
Weapon::Weapon(std::string _weapon_name)
{
	std::cout << GREEN << "Weapon created." << RESET << std::endl;
	setType(_weapon_name);
}
/* DECONSTRUCTOR */
Weapon::~Weapon(void)
{
	std::cout << RED << "Weapon destructed." << RESET << std::endl;
	return;
}