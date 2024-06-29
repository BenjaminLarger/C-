/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 16:29:16 by blarger           #+#    #+#             */
/*   Updated: 2024/06/29 14:58:47 by blarger          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/


#include "PmergeMe.hpp"

void	printList(std::list<int> l, const char *color)
{
	for (std::list<int>::iterator it = l.begin(); it != l.end(); ++it)
	{
		std::cout << color<< *it << ", ";
	}
	std::cout << RESET << std::endl;
}


bool	listIsSorted(std::list<int> l)
{
	for (std::list<int>::iterator it = l.begin(); it != l.end(); ++it)
	{
		std::list<int>::iterator next_it = it;
		++next_it;
		if (next_it != l.end() && *it > *next_it)
			return (false);
	}
	return (true);
}


bool	isListMin(std::list<int> main, int ref)
{
	for (std::list<int>::iterator	itMain = main.begin(); itMain != main.end(); ++itMain)
	{
		if (*itMain < ref)
			return (false);
	}
	return (true);
}

void	pushFirstElementToFront(std::list<int> &main, std::list<int> &aux)
{
	int	firstElement;

	if (!main.empty())
	{
		firstElement = main.front();
		aux.push_front(firstElement);
		main.pop_front();
		
	}
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
}




