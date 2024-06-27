/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:51:31 by blarger           #+#    #+#             */
/*   Updated: 2024/06/27 07:19:56 by blarger          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "BitcoinExchange.hpp"

void printDateValuePair(const std::pair<Date, double>& pair)
{
    std::cout << "Date: " << pair.first.getDay() << "/"
              << pair.first.getMonth() << "/"
              << pair.first.getYear()
              << ", Value: " << pair.second << std::endl;
}

/* ------------------------DATE CLASS */

/* CONSTRUCTORS */
Date::Date(unsigned int d, unsigned int m, unsigned int y) : day(d), month(m), year(y)
{
	if (d > 31 || d == 0 || m > 12 || m == 0)
	{
		std::ostringstream oss;
        oss << "Error : bad input => " << y << "-" << m << "-" << d << std::endl;
		throw std::out_of_range(oss.str());
	}
}
Date::Date() :day(06), month(01), year(2001) {};

Date::~Date() {};

Date::Date(const Date &stack)
{
	this->day = stack.day;
	this->month = stack.month;
	this->year = stack.year;

}

/* OPERATORS */
Date 	&Date::operator=(const Date &F)
{
	this->day = F.day;
	this->month = F.month;
	this->year = F.year;
	return (*this);
}

/* GETTERS */
unsigned int	Date::getDay() const { return (this->day);}
unsigned int	Date::getMonth() const {return (month);}
unsigned int	Date::getYear() const {return (year);}
