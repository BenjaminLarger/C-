/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:51:44 by blarger           #+#    #+#             */
/*   Updated: 2024/06/26 16:13:44 by blarger          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#pragma once
#ifndef EASYFIND_HPP
#define EASYFIND_HPP

// ----------INCLUDE
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <utility> // std::pair
#include <stdexcept> // std::runtime_error
#include <sstream> // std::stringstream
#include <utility>
#include <sstream> // Include for std::istringstream
#include <string>  // Include for std::string
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

// ----------MESSAGES
#define BAD_INPUT "This program only accept 1 file passed as argument!"

// ************************************************************************** //
//                               Class                                		  //
// ************************************************************************** //

struct Date
{
	private:
	    unsigned int day;
    	unsigned int month;
	    unsigned int year;
		
	public:
		Date(unsigned int d, unsigned int m, unsigned int y);
		Date();
		~Date();
		Date(const Date &stack);
		Date 		&operator=(const Date &F);

		unsigned int	getDay() const ;
		unsigned int	getMonth() const ;
		unsigned int	getYear() const ;
};

typedef std::vector<std::pair<Date, double> > DateDoublePairVector;

/* UTILS FUNCTIONS */
void printDateValuePair(const std::pair<Date, double>& pair);

#endif
