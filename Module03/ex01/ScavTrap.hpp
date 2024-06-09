/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 09:26:02 by blarger           #+#    #+#             */
/*   Updated: 2024/06/09 11:22:07 by blarger          ###   ########.fr       */
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

class ScavTrap : public ClapTrap {

private:

public:
	ScavTrap();
	ScavTrap(std::string _name);
	ScavTrap(const ScavTrap& other);
	~ScavTrap(void);

	void			guardGate(void);
	virtual void	attack(const std::string& target);

};

#endif