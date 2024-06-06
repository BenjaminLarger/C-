/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 09:32:47 by blarger           #+#    #+#             */
/*   Updated: 2024/06/06 15:40:24 by blarger          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Weapon.hpp"

const std::string &Weapon::getType(void)
{
	std::string	&ref = this->type;
	return (ref);
}

void Weapon::setType(std::string _type)
{
	this->type = _type;
}

/* CONSTRUCTOR */
Weapon::Weapon(std::string _weapon_name)
{
	setType(_weapon_name);
}

/* DECONSTRUCTOR */
Weapon::~Weapon(void)
{
	return;
}
