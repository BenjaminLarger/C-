/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 16:26:24 by blarger           #+#    #+#             */
/*   Updated: 2024/06/10 15:07:55 by blarger          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#pragma once
#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

// ----------INCLUDE
#include <iostream> 

// ----------COLORS
#define RESET   "\033[0m"
#define BLACK   "\033[30m"
#define RED     "\033[1;31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define ORANGE "\033[38;5;214m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[1; 37m"

// ************************************************************************** //
//                               Class                                		  //
// ************************************************************************** //

class ClapTrap {

private:
	std::string		name;
	unsigned int	points;
	unsigned int	energyPoints;
	unsigned int	attackDamage;
	
public:
	ClapTrap();
	ClapTrap(std::string _name);
	ClapTrap(std::string _name, unsigned int points, unsigned int energyPoints, unsigned int attackDamage);
	ClapTrap(const ClapTrap& other);
	~ClapTrap(void);

	std::string		getName(void) const;
	unsigned int	getPoints(void) const;
	unsigned int	getEnergyPoints(void) const;
	unsigned int	getAttackDamage(void) const;

	void	setEnergyPoints(unsigned int new_points);

	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
};

#endif