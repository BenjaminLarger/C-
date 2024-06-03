/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 09:32:59 by blarger           #+#    #+#             */
/*   Updated: 2024/06/03 16:29:09 by blarger          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "HumanA.hpp"

void	HumanA::attack(void)
{
	std::cout << name << ATTACK << weapon.getType() << std::endl;
}

/* CONSTRUCTOR */
HumanA::HumanA(const std::string _name, Weapon& _weapon) : name(_name), weapon(_weapon)
{
	return ;
}

/* DECONSTRUCTOR */
HumanA::~HumanA(void)
{
	return ;
}