/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:49:49 by blarger           #+#    #+#             */
/*   Updated: 2024/06/27 07:47:07 by blarger          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	try
	{
		if (argc != 2)
			throw (std::runtime_error(BAD_INPUT));
		DateDoublePairVector dataPairs;
		dataPairs = read_csv("data.csv", ',', dataPairs);
		DateDoublePairVector inputPairs = read_csv(argv[1], '|', dataPairs);
	}
	catch (const std::out_of_range& e)
	{
		std::cout << RED  << e.what() << RESET << std::endl;
	}
	catch(const std::runtime_error& e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}
	catch(...)
	{
		std::cout << RED << "Unknown error: " << RESET << std::endl;
	}
	
	return (0);
}