/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readCSV.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 18:06:24 by blarger           #+#    #+#             */
/*   Updated: 2024/07/12 13:23:55 by blarger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <cmath>

unsigned int	findTokenizedDate(std::string dateTokenized)
{
	unsigned int	result;

	std::istringstream	iss(dateTokenized);
	iss >> result;
	return (result);
}

static bool	correctDate(std::string str)
{
	int	i = 0;

//	std::cout << str << std::endl;
	for (; i < 4; i++)
	{
		//std::cout << BLUE << str[i] << RESET;
		if (!isdigit(str[i]))
			return (false);
	}
	//std::cout << WHITE << str[i];
	if (str[i++] != '-')
		return (false);
	for (; i < 7; i++)
	{
		//std::cout << RED << str[i];
		if (!isdigit(str[i]))
			return (false);
	}
	//std::cout << BLUE << str[i];
	if (str[i++] != '-')
		return (false);
	for (; i < 10; i++)
	{
		//std::cout << WHITE << str[i];
		if (!isdigit(str[i]))
			return (false);
	}
	return (true);
}

Date	getDate(const std::string &s)
{
	//std::cout << "_---------------------------\n";
    std::pair<Date, double> btcPair;
    std::stringstream ss(s);
    std::string yearStr, monthStr, dayStr;
    std::getline(ss, yearStr, '-');
	unsigned int year = findTokenizedDate(yearStr); 
	std::getline(ss, monthStr, '-');
	//std::cout << monthStr << std::endl;
	unsigned int month = findTokenizedDate(monthStr); 
	std::getline(ss, dayStr, '-');
	unsigned int day = findTokenizedDate(dayStr); 
	/* if (correctDate(yearStr) == false || correctDate(monthStr) == false || correctDate(dayStr) == false)
		throw (std::out_of_range("Incorrect input date!\n")); */
	Date	btcDate(day, month, year);
	//std::cout << "_---------------------------\n";
   	return btcDate;

}

bool	restIsWhiteSpace(std::string str)
{
	int	i = 0;

	while (str[i] && str[i] == ' ')
		i++;
	
	if (str[i] == '\0')
		return (true);
	else
		return (false);
}

double roundToTwoDigits(double value)
{
    return static_cast<int>(value * 100 + 0.5) / 100.0;
}

double	getBtcPrice(const std::string &s, char sep)
{
	std::stringstream ss(s);
	std::string	priceStr;

	std::getline(ss, priceStr, sep);
	std::getline(ss, priceStr);

	bool	hasANumber = false;

	if (priceStr[0] == '.' || (priceStr[0] == ' ' && priceStr[1] == '.'))
		throw std::out_of_range("Error: invalid number.\n");
	for (int i = 0; priceStr[i]; i++)
	{
		if (i == 0 && priceStr[i] == ' ')
			i++;
		if ((priceStr[i] == '-') && (i != 0 && priceStr[i - 1] != ' '))
   			throw std::out_of_range("Error: invalid number.\n");
		if ((priceStr[i] < '0' || priceStr[i] > '9') && priceStr[i] != '.' && priceStr[i] != '-' && restIsWhiteSpace(&priceStr[i]) == false)
			throw std::out_of_range("Error: price is not a number.\n");
		else if (priceStr[i] >= '0' && priceStr[i] <= '9')
		{
			hasANumber = true;
		}
	}

	double btcPrice = atof(priceStr.c_str());
	if (btcPrice > 2147483647)
		throw std::out_of_range("Error: too large a number.\n");
	if (btcPrice != btcPrice)
		throw std::out_of_range("Error: NAN.\n");
	if (btcPrice > 1000)
		throw std::out_of_range("");
	if (btcPrice < 0)
		throw std::out_of_range("Error: not a positive number.\n");
	if (hasANumber == false)
		throw std::out_of_range("Error: input has no number.\n");
	return (btcPrice);
}

bool	isInvalidLine(std::string line, char sep)
{
	int	i = 0;
	int	numberOfDash = 0;

	if (line[i] < '0' || line[i] > '9')
		return (false);
	while (line[i] && line[i] != sep)
	{
		if (line[i] == '-')
			numberOfDash++;
		if (line[i] == ' ' && (numberOfDash != 2))
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

    if (!file.is_open() && sep == '|')
	{
        throw std::runtime_error("Error: Could not open file.");
    }
    while (std::getline(file, line))
	{
		try
		{
			if (correctDate(line) == false || isInvalidLine(line, sep) == false)
				throw (std::out_of_range(""));
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