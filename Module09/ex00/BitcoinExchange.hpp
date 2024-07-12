/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:51:44 by blarger           #+#    #+#             */
/*   Updated: 2024/06/27 16:39:40 by blarger          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#pragma once
#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

// ----------INCLUDE
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <utility>
#include <stdexcept>
#include <sstream>
#include <utility>
#include <sstream>
#include <string> 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cmath>

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
#define BAD_INPUT "Error: could not open file."

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

/* ---------------------UTILS FUNCTIONS */
/* READ_CSV */
void 					printDateValuePair(const std::pair<Date, double>& pair);
unsigned int			findTokenizedDate(std::string dateTokenized);
Date					getDate(const std::string &s);
double					getBtcPrice(const std::string &s, char sep);
DateDoublePairVector	read_csv(const std::string& filename, char sep, DateDoublePairVector dataPairs);
void					matchPairs(std::pair<Date, double> inputDate,DateDoublePairVector fixedPairs);
/* CREATE PAIR */
bool					dateAreDifferent(Date fixedPairs, Date inputDate);
bool					fixedDateIsEarlierThanInput(Date fixedPairs, Date inputDate);
double					getBtcPrice(double nbOfBtc, double btcPrice);
void					matchPairs(std::pair<Date, double> inputDate,DateDoublePairVector fixedPairs);


#endif
