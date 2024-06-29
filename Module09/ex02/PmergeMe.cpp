/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 16:29:16 by blarger           #+#    #+#             */
/*   Updated: 2024/06/29 14:46:20 by blarger          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "PmergeMe.hpp"

std::list<int>	sortEachPair(std::list<int> main, std::list<int> aux)
{
	std::list<int>::iterator	it1 = main.begin();
	std::list<int>::iterator	nextIt1 = main.begin();
	std::list<int>::iterator	it2 = aux.begin();
	std::list<int>::iterator	nextIt2 = aux.begin();

	++nextIt2;
	++nextIt1;

	while (nextIt2 != aux.end())
	{
		if (*it2 > *nextIt2)
		{
			std::iter_swap(it2, nextIt2);
            std::iter_swap(it1, nextIt1);
	
		}
		++it2;
		++nextIt2;
		++it1;
		++nextIt1;
	}
	if (listIsSorted(aux) == true)
		return (aux);
	else
		return (sortEachPair(main, aux));
}

std::list<int>	mergedSortedList(std::list<int> &main,std::list<int> &aux, long unsigned int index, const long unsigned int originalSize)
{
	std::list<int>::iterator	itMain = main.begin();
	std::list<int>::iterator	itAux = aux.begin();

	printList(main, YELLOW);
	printList(aux, GREEN);
	if (index >= aux.size())
		index = 0;

	std::advance(itAux, index);

	while (itMain != main.end())
	{
		if (*itMain == *itAux || (*itMain < *itAux && isListMin(main, *itMain)))
		{
			aux.insert(itAux, *itMain);
			itMain = main.erase(itMain);
			itAux = aux.begin();
		}
		else
			++itMain;
	}
	if ((listIsSorted(aux) == true && aux.size() == originalSize))
		return (aux);
	else
		return (mergedSortedList(main, aux, index + 1, originalSize));
}

std::list<int>	insertStruggler(std::list<int> &aux, int ref)
{
	for (std::list<int>::iterator itAux = aux.begin(); itAux != aux.end(); ++itAux)
	{
		if (*itAux == ref || ref < *itAux)
		{
			aux.insert(itAux, ref);
	
			return (aux);
		}
	}
	aux.push_back(ref);
	return (aux);
}	

