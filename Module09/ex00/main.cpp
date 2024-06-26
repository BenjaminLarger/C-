/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:49:49 by blarger           #+#    #+#             */
/*   Updated: 2024/06/26 18:35:25 by blarger          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "BitcoinExchange.hpp"

bool	dateAreDifferent(Date fixedPairs, Date inputDate)
{
	if (fixedPairs.getYear() == inputDate.getYear()
		&& fixedPairs.getMonth() == inputDate.getMonth()
		&& fixedPairs.getDay() == inputDate.getDay())
		return (false);
	else
		return (true);
}

bool	fixedDateIsEarlierThanInput(Date fixedPairs, Date inputDate)
{
	//std::cout << MAGENTA << "Fixed Date: " << fixedPairs.getDay() << '/' << fixedPairs.getMonth() << '/' << fixedPairs.getYear() << std::endl;
    //std::cout << "Input Date: " << inputDate.getDay() << '/' << inputDate.getMonth() << '/' << inputDate.getYear() << RESET << std::endl;
	if (fixedPairs.getYear() < inputDate.getYear())
		return (true);
	else if (fixedPairs.getYear() > inputDate.getYear())
		return (false);
	if (fixedPairs.getMonth() < inputDate.getMonth())
		return (true);
	else if (fixedPairs.getMonth() > inputDate.getMonth())
		return (false);
	if (fixedPairs.getDay() < inputDate.getDay())
		return (true);
	else
		return (false);
}

double	getBtcPrice(double nbOfBtc, double btcPrice)
{
	//std::cout << BLUE << "nb of btc = " << nbOfBtc << " | btc price = " << btcPrice << RESET << std::endl;
	return (nbOfBtc * btcPrice);
}

void	matchPairs(DateDoublePairVector inputPairs,DateDoublePairVector fixedPairs)
{
	size_t	j = 0;
	for (size_t i = 0; i < inputPairs.size(); i++)
	{
		j = 0;
		while (j < fixedPairs.size())
		{
			if (fixedDateIsEarlierThanInput(inputPairs[i].first, fixedPairs[j].first) == true)
				break ;
			j++;
		}
		//std::cout << BLUE << "i = " << i << RESET << std::endl;
		if (fixedPairs.size() > 1 && (j != fixedPairs.size() || (j == fixedPairs.size() && dateAreDifferent(inputPairs[i].first, fixedPairs[j - 1].first) == true)))
			j--;
		std::cout << inputPairs[i].first.getYear() << "-" << inputPairs[i].first.getMonth() << "-" << inputPairs[i].first.getDay() << " => " << inputPairs[i].second << " = " << getBtcPrice(inputPairs[i].second, fixedPairs[j].second) << std::endl;
	}
}

int main(int argc, char **argv)
{
//	std::vector<std::pair<std::string, std::vector<int> > > fileContent;

	try
	{
		if (argc != 2)
			throw (std::runtime_error(BAD_INPUT));
		DateDoublePairVector dataPairs = read_csv("data.csv", ',');
		std::cout << YELLOW << "----------------------------------------------" << RESET << std::endl;
		DateDoublePairVector inputPairs = read_csv(argv[1], '|');
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