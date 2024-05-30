/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 16:26:24 by blarger           #+#    #+#             */
/*   Updated: 2024/05/30 17:20:30 by blarger          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#pragma once
#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

// ----------INCLUDE

#include <iostream>

// ----------DEFINITION

#define MAIN "Type NAME to name a new zombie; or type RANDOM to randomize the zombie new name; type EXIT to quit the program: "
#define NAME "Find a name for your new zombie: "

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
	static Zombie	*name_zombie(void);
	static void random_chump(std::string name);


private:
	std::string name;


};

// ----------FUNCTIONS
std::string		prompt_user(const char *prompt, const char *color);
std::string	generate_random_name(void);

#endif