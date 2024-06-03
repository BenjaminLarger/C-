/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 16:26:24 by blarger           #+#    #+#             */
/*   Updated: 2024/06/03 13:02:18 by blarger          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#pragma once
#ifndef HARL_HPP
#define HARL_HPP

// ----------INCLUDE

#include <iostream>
#include <cerrno>
#include <ostream>
#include <map>

// ----------DEFINITION

#define PROMPT "What kind of comments are you willing to do ? {INFO, DEBUG, WARNING, or ERROR): "
# define DEBUG "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"
# define INFO "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!"
# define WARNING "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month."
# define ERROR  "This is unacceptable! I want to speak to the manager now."

// ----------COLORS
#define RESET   "\033[0m"
#define BLACK   "\033[30m"
#define RED     "\033[1;31m"
#define ORANGE "\033[38;5;214m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[1; 37m"

// ----------FORWARD DECLERARTION

// ************************************************************************** //
//                               Class                                //
// ************************************************************************** //

class Harl {
public:

	Harl(void);
	~Harl (void);
	void complain( std::string level );
	

private:
	void debug( void );
	void info( void );
	void warning( void );
	void error( void );
	
	std::map<std::string, void (Harl::*)()> levelMap;
};

// ----------FUNCTIONS


#endif