/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:49:49 by blarger           #+#    #+#             */
/*   Updated: 2024/06/28 17:02:15 by blarger          ###   ########.fr       */
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
		}
		std::istringstream iss(argv[i]);
		iss >> value;
		input.push_back(value);
		printList(input, YELLOW);
	}
	return (input);
}

std::list<int>	mergeSortedList(std::list<int> main, std::list<int> aux)
{
	std::list<int>	result;
	std::list<int>::const_iterator	it1 = main.begin();
	std::list<int>::const_iterator	it2 = aux.begin();

	while (it1 != main.end() && it2 != aux.end())
	{
		if (*it1 < *it2)
		{
			result.push_back(*it1);
			++it1;			
		}
		else
		{
			result.push_back(*it2);
			++it2;
		}
	}
	while(it1 != main.end())
	{
		result.push_back(*it1);
		++it1;
	}
	while(it2 != aux.end())
	{
		result.push_back(*it2);
		++it2;
	}
	return (result);
}

std::list<int>	sortEachPair(std::list<int> main, std::list<int> aux);

void	fordJohnsonSort(std::list<int> main)
{
	std::list<int>	aux;
	int	struggler;
	std::list<int>::iterator it;

	if (main.size() < 2)
		return ;
	
	if (main.size() % 2 == 1)
	{
		it = main.end();
		std::cout << RESET << "end it = " << *it << std::endl;
		--it;
		std::cout << RESET << "end-- it = " << *it << std::endl;
		struggler = *it;
		main.erase(it);
		std::cout << RESET << "erase it = " << *it << std::endl;
	}
	it = main.begin();
	std::cout << RESET << "start it = " << *it << std::endl;
	while (aux.size() < main.size() && it != main.end())
	{
		std::list<int>::iterator next_it = it;
		++next_it;
		if (next_it != main.end() && *it > *next_it)
		{
			std::iter_swap(it, next_it);
		}
		aux.push_back(*next_it);
		it = main.erase(next_it);
	}
	
	//aux.sort();
	fordJohnsonSort(main);
	fordJohnsonSort(aux);

	printList(main, YELLOW);
	printList(aux, ORANGE);
//	main = sortEachPair(main, aux);	
	//main = mergeSortedList(main, aux);
	/* printList(main, YELLOW); */
	(void)struggler;
}

int main(int argc, char **argv)
{
	try
	{
		if (argc < 2)
			throw (std::runtime_error(BAD_INPUT));
		displayNbBeforeOrdering(argv);
		//std::map<int, int>	pairs = groupElements(argv, argc);
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