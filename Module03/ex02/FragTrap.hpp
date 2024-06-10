/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 11:29:14 by blarger           #+#    #+#             */
/*   Updated: 2024/06/09 11:34:53 by blarger          ###   ########.fr       */
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

class FragTrap : public ClapTrap {

private:

public:
	FragTrap();
	FragTrap(std::string _name);
	FragTrap(const FragTrap& other);
	~FragTrap(void);

	void	highFivesGuys(void);

};

#endif