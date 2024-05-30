/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 16:26:24 by blarger           #+#    #+#             */
/*   Updated: 2024/05/30 21:14:38 by blarger          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#pragma once
#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

// ----------INCLUDE

#include <iostream>
#include <cerrno>
#include <cstring>
#include <stdlib.h>

// ----------DEFINITION

#define MAIN "How many zombies do you want to create? "
# define N_PROMPT "Provide only the name of the zombies as parameter."

// ----------COLORS
#define RESET   "\033[0m"
#define BLACK   "\033[30m"
#define RED     "\033[1;31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[1; 37m"

// ************************************************************************** //
//                               Account Class                                //
// ************************************************************************** //
class Zombie {


public:

	Zombie  (void);
	~Zombie (void);
    void    announce(void)
	{
		 std::cout << RESET << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
	}
	void 	set_name(const std::string& _name) {name = _name;}
	Zombie	*next;

private:
	std::string name;


};

// ----------FUNCTIONS
int			prompt_user_N(const char *prompt, const char *color);
std::string	prompt_user(const char *prompt, const char *color);
Zombie*		zombieHorde( int N, std::string name );


#endif