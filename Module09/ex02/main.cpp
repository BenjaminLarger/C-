/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:49:49 by blarger           #+#    #+#             */
/*   Updated: 2024/06/30 10:48:07 by blarger          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "PmergeMe.hpp"

//https://github.com/nerraou/Ford-Johnson-algorithm/tree/master?tab=readme-ov-file

int main(int argc, char **argv)
{
	try
	{
		if (argc < 2)
			throw (std::runtime_error(BAD_INPUT));
		displayNbBeforeOrdering(argv);
		std::list<int> inputs = convertDataInputIntoList<std::list<int> >(argv, argc);
		inputs = fordJohnsonSort<std::list<int> >(inputs);
		displayNbAfterOrdering(inputs);
		
		std::deque<int> dequeInputs = convertDataInputIntoList<std::deque<int> >(argv, argc);
		dequeInputs = fordJohnsonSort<std::deque<int> >(dequeInputs);
		displayNbAfterOrdering(dequeInputs);
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