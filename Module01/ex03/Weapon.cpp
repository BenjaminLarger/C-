/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 09:32:47 by blarger           #+#    #+#             */
/*   Updated: 2024/06/03 15:52:12 by blarger          ###   ########.fr       */
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
	setType(_weapon_name);
}

/* DECONSTRUCTOR */
Weapon::~Weapon(void)
{
	return;
}
