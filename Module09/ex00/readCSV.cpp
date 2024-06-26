/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readCSV.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 18:06:24 by blarger           #+#    #+#             */
/*   Updated: 2024/06/26 18:07:08 by blarger          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "BitcoinExchange.hpp"

unsigned int	findTokenizedDate(std::string dateTokenized)
{
	unsigned int	result;

	std::istringstream	iss(dateTokenized);
	iss >> result;
	return (result);
}


Date	getDate(const std::string &s)
{
    std::pair<Date, double> btcPair;
    std::stringstream ss(s);
    std::string yearStr, monthStr, dayStr;
    std::getline(ss, yearStr, '-');
	unsigned int year = findTokenizedDate(yearStr); 
	std::getline(ss, monthStr, '-');
	unsigned int month = findTokenizedDate(monthStr); 
	std::getline(ss, dayStr, '-');
	unsigned int day = findTokenizedDate(dayStr); 
	Date	btcDate(day, month, year);
   	return btcDate;

}

double	getBtcPrice(const std::string &s, char sep)
{
	std::stringstream ss(s);
	std::string	priceStr;

	std::getline(ss, priceStr, sep);
	std::getline(ss, priceStr);

	std::cout << YELLOW << priceStr << RESET << std::endl;
	double btcPrice = atof(priceStr.c_str());
	std::cout << YELLOW << btcPrice << RESET << std::endl;
	if (btcPrice > 1000 || btcPrice < 0)
		throw std::out_of_range("BTC price out of range");
	return (btcPrice);
}
DateDoublePairVector read_csv(const std::string& filename, char sep)
{
    std::ifstream file(filename.c_str()); 
    std::string line;
	DateDoublePairVector myPairs;

    if (!file.is_open())
	{
        std::cerr << "Error opening file: " << filename << std::endl;
        throw std::runtime_error("Could not open file");
    }

    while (std::getline(file, line))
	{
		try
		{
			Date	date = getDate(line);
			double btcPrice = getBtcPrice(line, sep);
			std::pair<Date, double> btcPair = std::make_pair(date, btcPrice);
			myPairs.push_back(btcPair);
			printDateValuePair(btcPair);
		}
		catch(const std::exception& e)
		{
			//std::cerr << RED << e.what() << RESET << std::endl;
		}
    }

    file.close();
	return (myPairs);
}