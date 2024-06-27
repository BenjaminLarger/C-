/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readCSV.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 18:06:24 by blarger           #+#    #+#             */
/*   Updated: 2024/06/27 07:49:09 by blarger          ###   ########.fr       */
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

	double btcPrice = atof(priceStr.c_str());
	if (btcPrice > 2147483647)
		throw std::out_of_range("Error: too large a number\n");
	if (btcPrice != btcPrice)
		throw std::out_of_range("Error: NAN\n");
	if (btcPrice > 1000)
		throw std::out_of_range("");
	if (btcPrice < 0)
		throw std::out_of_range("Error: not a positive number.\n");
	return (btcPrice);
}

bool	isInvalidLine(std::string line, char sep)
{
	int	i = 0;
	int	numberOfDash = 0;

	while (line[i] && line[i] != sep)
	{
		if (line[i] == '-')
			numberOfDash++;
		if (line[i] == ' ' && (numberOfDash != 2 /* || !isalpha(line[i - 1]) */))
			return (false);
		if (line[i] != ' ' && (line[i] < '0' || line[i] > '9') && line[i] != '-')
			return (false);
		i++;
	}
	if (numberOfDash != 2)
		return (false);
	return (true);
}

DateDoublePairVector read_csv(const std::string& filename, char sep, DateDoublePairVector dataPairs)
{
    std::ifstream file(filename.c_str()); 
    std::string line;
	DateDoublePairVector myPairs;

    if (!file.is_open())
	{
        throw std::runtime_error("Error : Could not open file");
    }

    while (std::getline(file, line))
	{
		try
		{
			if (isInvalidLine(line, sep) == false)
			{
				throw std::out_of_range("") ;
			}
			Date	date = getDate(line);
			double btcPrice = getBtcPrice(line, sep);
			std::pair<Date, double> btcPair = std::make_pair(date, btcPrice);
			myPairs.push_back(btcPair);
			if (sep == '|')
				matchPairs(btcPair, dataPairs);
		}
		catch(const std::exception& e)
		{
			if (sep == '|')
				std::cerr << RED << e.what() << RESET;
		}
    }

    file.close();
	return (myPairs);
}