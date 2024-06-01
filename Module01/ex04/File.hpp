/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   File.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 16:26:24 by blarger           #+#    #+#             */
/*   Updated: 2024/06/01 19:55:42 by blarger          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#pragma once
#ifndef WEAPON_HPP
#define WEAPON_HPP

// ----------INCLUDE

#include <iostream>
#include <cerrno>
#include <ostream>


// ----------DEFINITION

# define ATTACK " attacks with their "
# define ARGC "Program must take in 4 parameters"

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

// ----------FORWARD DECLERARTION


class File {


// ************************************************************************** //
//                               Class                                //
// ************************************************************************** //



public:

	File(std::string _weapon_name);
	~File (void);
	void				setWeapon(std::string _weapon_name);
	const std::string 	getType(void);
	void 				setType(/* const  */std::string _type);

private:
	std::string type;


};

// ----------FUNCTIONS


#endif