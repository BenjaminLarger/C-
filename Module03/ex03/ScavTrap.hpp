/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 09:26:02 by blarger           #+#    #+#             */
/*   Updated: 2024/06/10 14:51:26 by blarger          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#pragma once
#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

// ----------INCLUDE
#include "ClapTrap.hpp" 

// ************************************************************************** //
//                               Class                                		  //
// ************************************************************************** //

class ScavTrap : virtual public ClapTrap {

private:

public:
	ScavTrap();
	ScavTrap(std::string _name);
	ScavTrap(const ScavTrap& other);
	~ScavTrap(void);

	void					guardGate(void);
	virtual void			attack(const std::string& target);

	virtual unsigned int	getEnergyPoints();
};

#endif