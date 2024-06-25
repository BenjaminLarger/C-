/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:51:31 by blarger           #+#    #+#             */
/*   Updated: 2024/06/25 17:55:31 by blarger          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "BitcoinExchange.hpp"

/* --------------CONSTRUCTORS */
BitcoinExchange::BitcoinExchange()
{}

/* --------------DECONSTRUCTORS */
BitcoinExchange::~BitcoinExchange(void)
{
	std::cout << RED << "BitcoinExchange deconstructor called!" << RESET << std::endl;
}

/* --------------COPY */
BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : maxIntStockable(other.maxIntStockable)
{
	this->vector = other.vector;
    std::cout << GREEN << "BitcoinExchange calling copy assignment!" << RESET << std::endl;
}

/* --------------OPERATORS */
BitcoinExchange 		&BitcoinExchange::operator=(const BitcoinExchange &F)
{
	return (*this);
}

/* --------------GETTER */

/* --------------SETTER */


/* --------------FUNCTION MEMBER */