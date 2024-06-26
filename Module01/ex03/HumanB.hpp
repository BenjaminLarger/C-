/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 16:26:24 by blarger           #+#    #+#             */
/*   Updated: 2024/06/03 15:52:25 by blarger          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#pragma once
#ifndef HUMANB_HPP
#define HUMANB_HPP

// ----------INCLUDE

#include "Weapon.hpp"
#include <ostream>

// ************************************************************************** //
//                               Account Class                                //
// ************************************************************************** //
class HumanB {

public:

	HumanB(const std::string& _name);
	~HumanB (void);
	void	setWeapon(Weapon &_weapon);
	void	attack(void);
private:
	std::string name;
	Weapon *weapon;
};


#endif