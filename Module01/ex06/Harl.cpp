/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 20:30:07 by blarger           #+#    #+#             */
/*   Updated: 2024/06/06 16:20:12 by blarger          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Harl.hpp"

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

void Harl::complain( std::string level )
{
	int	i = 0;

	func		levelMap[] = { &Harl:: debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string	levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	while (i < 4 && levels[i].compare(level))
		i++;

    switch(i)
	{
		case 0:
			(this->*levelMap[0])();
			(this->*levelMap[1])();
			(this->*levelMap[2])();
			(this->*levelMap[3])();
			break ;

		case 1:
			(this->*levelMap[1])();
			(this->*levelMap[2])();
			(this->*levelMap[3])();
			break ;

		case 2:
			(this->*levelMap[2])();
			(this->*levelMap[3])();
			break ;

		case 3:
			(this->*levelMap[3])();
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

