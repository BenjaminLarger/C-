/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CreatePair.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 07:06:52 by blarger           #+#    #+#             */
/*   Updated: 2024/07/07 13:47:44 by blarger          ###   ########.fr       */
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
	return (nbOfBtc * btcPrice);
}

void	printDate(int expectedDigit, unsigned int nb, bool isDay)
{
	int	nbOfDigit = 0;
	int	nbCopy = nb;

	while (nbCopy > 0)
	{
		nbOfDigit++;
		nbCopy /= 10;
	}
	if (nb == 0)
		expectedDigit--;
	while (expectedDigit > nbOfDigit)
	{
		std::cout << "0";
		expectedDigit--;
	}
	std::cout << nb;
	if (isDay == false)
		std::cout << "-";
}

void	matchPairs(std::pair<Date, double> inputDate, DateDoublePairVector fixedPairs)
{
	size_t	j = 0;

	if (fixedPairs.size() == 0)
		return ;
	while (j < fixedPairs.size())
	{
		j++;
		if (fixedDateIsEarlierThanInput(inputDate.first, fixedPairs[j].first) == true)
			break ;
	}
	if (fixedPairs.size() > 1 && (j != fixedPairs.size() || (j == fixedPairs.size() && dateAreDifferent(inputDate.first, fixedPairs[j - 1].first) == true)))
		j--;
	std::cout << YELLOW;
	printDate(4, inputDate.first.getYear(), false);
	printDate(2, inputDate.first.getMonth(), false);
	printDate(2, inputDate.first.getDay(), true);
	std::cout << " => " << inputDate.second << " = " << getBtcPrice(inputDate.second, fixedPairs[j].second) << std::endl;
	std::cout << RESET;
}