/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:49:49 by blarger           #+#    #+#             */
/*   Updated: 2024/07/15 12:38:29 by blarger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	std::clock_t	start;
	std::clock_t	end;
	long unsigned int			originalSizeWithoutStruggler;

	try
	{
		if (argc < 2)
			throw (std::runtime_error(BAD_INPUT));

		displayNbBeforeOrdering(argv);
		std::list<int> listInputs = convertDataInputIntoList<std::list<int> >(argv, argc);
		start = std::clock();
		originalSizeWithoutStruggler = listInputs.size() - (listInputs.size() % 2);
		fordJohnsonSort<std::list<int> >(listInputs, originalSizeWithoutStruggler, true);
		end = std::clock();
		displayTimeToProcess(start, end, "list");
		
		std::deque<int> dequeInputs = convertDataInputIntoList<std::deque<int> >(argv, argc);
		start = std::clock();
		originalSizeWithoutStruggler = dequeInputs.size() - (dequeInputs.size() % 2);
		fordJohnsonSort<std::deque<int> >(dequeInputs, originalSizeWithoutStruggler, false);
		end = std::clock();
		displayTimeToProcess(start, end, "deque");
	}
	catch (const std::runtime_error& e)
	{
		std::cout << RED << "Error: "  << e.what() << RESET << std::endl;
	}
	catch (const std::out_of_range& e)
	{
		std::cout << RED << "Error: "  << e.what() << RESET << std::endl;
	}
	catch(...)
	{
		std::cout << RED << "Unknown error: " << RESET << std::endl;
	}
	
	return (0);
}