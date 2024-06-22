/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:14:46 by blarger           #+#    #+#             */
/*   Updated: 2024/06/19 18:52:51 by blarger          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#pragma once
#ifndef BASE_HPP
#define BASE_HPP

// ----------INCLUDE
#include <cstdlib> 
#include <iostream> 
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

// ----------COLORS
#define RESET   "\033[0m"
#define BLACK   "\033[30m"
#define RED     "\033[1;31m"
#define DARK_RED "\033[2;31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define ORANGE "\033[38;5;214m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[1; 37m"
#define GREY "\033[1;30m"

// ************************************************************************** //
//                               Class                                		  //
// ************************************************************************** //

class Base {

private:
	Base();
	
public:
	Base * generate(void);
	void identify(Base* p);
	void identify(Base& p);
};

#endif