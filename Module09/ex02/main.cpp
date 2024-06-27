/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:49:49 by blarger           #+#    #+#             */
/*   Updated: 2024/06/27 17:31:58 by blarger          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "PmergeMe.hpp"

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
}

std::list<int>	convertDataInputIntoList(char **argv, int argc)
{
	std::list<int>	input;
	int				value;	

	for (int i = 1; i < argc; i++)
	{
		for (int j = 0; argv[i][j]; j++)
		{
			if (!isdigit(argv[i][j]))
				throw (std::out_of_range("Invalid input."));
			std::istringstream iss(argv[i]);
			iss >> value;
			input.push_back(value);
		}
	}
	return (input);
}

void	fordJohnsonSort(std::list<int> main)
{
	std::list<int>	aux;

	if (main.size() < 2)
		return ;
	
	std::list<int>::iterator it = main.begin();
	while (it != main.end())
	{
		std::list<int>::iterator next_it = it;
		++next_it;
		if (next_it != main.end() && *it > *next_it)
			std::iter_swap(it, next_it);
		aux.push_back(*next_it);
		it = main.erase(next_it);
	}
	++it;
	aux.sort();
}

int main(int argc, char **argv)
{
	try
	{
		if (argc < 2)
			throw (std::runtime_error(BAD_INPUT));
		displayNbBeforeOrdering(argv);
		std::list<int> inputs= convertDataInputIntoList(argv, argc);
		fordJohnsonSort(inputs);
		
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