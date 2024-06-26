/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:49:49 by blarger           #+#    #+#             */
/*   Updated: 2024/06/26 16:14:33 by blarger          ###   ########.fr       */
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
	if (btcPrice > 1000 || btcPrice < 0)
		throw std::out_of_range("BTC price out of range");
	return (btcPrice);
}
std::vector<std::pair<Date, double> > read_csv(const std::string& filename, char sep) {
    std::ifstream file(filename.c_str()); 
    std::string line;
	std::vector<std::pair<Date, double> > myPairs;

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
			std::cerr << RED << e.what() << RESET << std::endl;
		}
    }

    file.close();
	return (myPairs);
}

void	matchPairs(std::vector<std::pair<Date, double> > inputPairs,std::vector<std::pair<Date, double> > dataPairs)
{
	std::vector<std::pair<Date, double> > = mstack.begin();
}

int main(int argc, char **argv)
{
	std::vector<std::pair<std::string, std::vector<int> > > fileContent;

	try
	{
		if (argc != 2)
			throw (std::runtime_error(BAD_INPUT));
		std::vector<std::pair<Date, double> > dataPairs = read_csv("data.csv", ',');
		std::cout << YELLOW << "----------------------------------------------" << RESET << std::endl;
		std::vector<std::pair<Date, double> > inputPairs = read_csv(argv[1], '-');
		std::cout << YELLOW << "----------------------------------------------" << RESET << std::endl;
		matchPairs(inputPairs, dataPairs);
	}
	catch(const std::runtime_error& e)
	{
		std::cerr << RED << "ERROR: " << e.what() << RESET << std::endl;
	}
	catch(...)
	{
		std::cerr << RED << "Unknown error: " << RESET << std::endl;
	}
	
	return (0);
}