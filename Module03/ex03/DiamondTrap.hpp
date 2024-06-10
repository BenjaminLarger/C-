/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 11:43:49 by blarger           #+#    #+#             */
/*   Updated: 2024/06/10 14:47:10 by blarger          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#pragma once
#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

// ----------INCLUDE
#include "ClapTrap.hpp" 
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

// ************************************************************************** //
//                               Class                                		  //
// ************************************************************************** //

class DiamondTrap : public ScavTrap, public FragTrap {

private:
	std::string		name;

public:
	DiamondTrap();
	DiamondTrap(std::string _name);
	DiamondTrap(const DiamondTrap& other);
	~DiamondTrap(void);

	void			attack(const std::string &target);
	std::string		getName(void) const;

	void	whoAmI(void);

};

#endif