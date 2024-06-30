/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:49:49 by blarger           #+#    #+#             */
/*   Updated: 2024/06/30 14:28:04 by blarger          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "PmergeMe.hpp"

//https://github.com/nerraou/Ford-Johnson-algorithm/tree/master?tab=readme-ov-file

void	displayTimeToProcess(std::clock_t start, std::clock_t end, std::string containerUsed)
{
	double duration = (end - start) * (1000000 / CLOCKS_PER_SEC);

	std::cout << "Time to process a range of 3000 elements with std::" << containerUsed << " : " << duration << " us" << std::endl;
}

void	displayNbBeforeOrdering(char **argv)
{
	int	i = 1;

	std::cout << "Before:	";
	while (argv[i])
	{
		std::cout << argv[i];
		i++;
		if (argv[i])
			std::cout << " ";	
	}
	std::cout << std::endl;
	if (i == 2)
	{
		std::cout << "After:	" << argv[1] << std::endl;
	}
}

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
		/* std::cout << GREEN;
		displayNbAfterOrdering(dequeCheckedInputs);
		std::cout << RESET; */
	}
	catch (const std::runtime_error& e)
	{
		std::cout << RED << "Error: "  << e.what() << RESET << std::endl;
	}
	catch (const std::out_of_range& e)
	{
		std::cout << RED << "Error"  << e.what() << RESET << std::endl;
	}
	catch(...)
	{
		std::cout << RED << "Unknown error: " << RESET << std::endl;
	}
	
	return (0);
}