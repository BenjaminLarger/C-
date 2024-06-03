/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 20:30:07 by blarger           #+#    #+#             */
/*   Updated: 2024/06/03 15:44:59 by blarger          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Harl.hpp"

/* CONSTRUCTOR */
Harl::Harl(void)
{
	levelMap["DEBUG"] = std::make_pair(1, &Harl::debug);
	levelMap["INFO"] = std::make_pair(2, &Harl::info);
	levelMap["WARNING"] = std::make_pair(3, &Harl::warning);
	levelMap["ERROR"] = std::make_pair(4, &Harl::error);

	return ;
}

/* DECONSTRUCTOR */
Harl::~Harl(void)
{
	return;
}

void Harl::complain( std::string level )
{
    switch(this->levelMap[level].first)
	{
		case 1:
			display_msg(DEBUG);
			display_msg(INFO);
			display_msg(WARNING);
			display_msg(ERROR);
			break ;

		case 2:
			display_msg(INFO);
			display_msg(WARNING);
			display_msg(ERROR);
			break ;

		case 3:
			display_msg(WARNING);
			display_msg(ERROR);
			break ;

		case 4:
			display_msg(ERROR);
			break ;
		default:
			print_error(COMP);
			break ;
	}
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

