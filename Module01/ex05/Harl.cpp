/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 20:30:07 by blarger           #+#    #+#             */
/*   Updated: 2024/06/03 17:16:21 by blarger          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Harl.hpp"

/* FUNCTION TO MEMBER: 

	levelMap[level]: This looks up the function pointer associated
with the key level in the levelMap map.

	this->*: This is the syntax for dereferencing a member function pointer.
It means "the member function of this pointed to by...".

	(this->*levelMap[level])(): This calls the member function pointed to by
levelMap[level] on the current object (this).

	So, if level is "DEBUG", and levelMap["DEBUG"] is a pointer to the debug
function, this line would call this->debug().
*/

void Harl::complain( std::string level )
{
	if (levelMap.find(level) != levelMap.end())
		(this->*levelMap[level])();
	else
		std::cout << RED << "Invalid comments: " << level << RESET << std::endl;
}

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
