/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 20:30:07 by blarger           #+#    #+#             */
/*   Updated: 2024/06/03 13:00:40 by blarger          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Harl.hpp"

/* CONSTRUCTOR */
Harl::Harl(void)
{
	levelMap["DEBUG"] = &Harl::debug;
	levelMap["WARNING"] = &Harl::warning;
	levelMap["INFO"] = &Harl::info;
	levelMap["ERROR"] = &Harl::error;
	return ;
}
/* DECONSTRUCTOR */
Harl::~Harl(void)
{
	return;
}

void Harl::complain( std::string level )
{
	if (levelMap.find(level) != levelMap.end())
		(this->*levelMap[level])();
	else
		std::cout << RED << "Invalid comments: " << level << RESET << std::endl;
}

void Harl::debug( void )
{
	std::cout << ORANGE << DEBUG << RESET << std::endl;
}

void	Harl::info(void)
{
	std::cout << ORANGE << INFO << RESET << std::endl;
}

void	Harl::warning(void)
{
	std::cout << ORANGE << WARNING << RESET << std::endl;
}

void	Harl::error(void)
{
	std::cout << ORANGE << ERROR << RESET << std::endl;
}

