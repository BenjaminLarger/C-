/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HUMAN_A.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 16:26:24 by blarger           #+#    #+#             */
/*   Updated: 2024/05/31 08:31:36 by blarger          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#pragma once
#ifndef HUMANA_HPP
#define HUMANA_HPP

// ----------INCLUDE
#include "Weapon.hpp"


// ************************************************************************** //
//                               Account Class                                //
// ************************************************************************** //
class HumanA {


public:

	HumanA(std::string _name, Weapon& _weapon);
	~HumanA (void);

	void	attack(void);
	//void	setWeapon(Weapon _weapon);
private:
	std::string name;
    Weapon 		&weapon;
};

#endif