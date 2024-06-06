/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 20:30:07 by blarger           #+#    #+#             */
/*   Updated: 2024/06/06 16:04:17 by blarger          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Harl.hpp"

void Harl::complain( std::string level )
{
	func		funct[] = { &Harl:: debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string	levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int			i = 0;

	while (i < 4 && levels[i].compare(level))
		i++;
	if (i < 4)
		(this->*funct[i])();
	else
		std::cout << RED << "Invalid comments: " << level << RESET << std::endl;
}

/* CONSTRUCTOR */
Harl::Harl(void)
{
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
