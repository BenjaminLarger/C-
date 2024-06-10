/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 11:29:14 by blarger           #+#    #+#             */
/*   Updated: 2024/06/10 15:10:19 by blarger          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#pragma once
#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

// ----------INCLUDE
#include "ClapTrap.hpp" 

// ************************************************************************** //
//                               Class                                		  //
// ************************************************************************** //

class FragTrap : virtual public ClapTrap {

private:
	static unsigned int	points;

public:
	FragTrap();
	FragTrap(std::string _name);
	FragTrap(const FragTrap& other);
	~FragTrap(void);

	std::string				getName(void) const;

	void					highFivesGuys(void);

	virtual unsigned int	getPoints(void) const ;
	unsigned int			getAttackDamage(void) const;


};

#endif