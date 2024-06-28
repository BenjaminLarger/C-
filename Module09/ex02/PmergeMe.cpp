/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 16:29:16 by blarger           #+#    #+#             */
/*   Updated: 2024/06/28 15:47:21 by blarger          ###   ########.fr       */
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

