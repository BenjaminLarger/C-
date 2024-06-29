/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:51:44 by blarger           #+#    #+#             */
/*   Updated: 2024/06/29 14:58:32 by blarger          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#pragma once
#ifndef RPN_HPP
#define RPN_HPP

// ----------INCLUDE
#include <iostream>
#include <stack>
#include <sstream>
#include <string>
#include <list>
#include <map>
#include <algorithm> 


// ----------COLORS
#define RESET   "\033[0m"
#define BLACK   "\033[30m"
#define RED     "\033[1;31m"
#define DARK_RED "\033[2;31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define ORANGE "\033[38;5;214m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[1; 37m"
#define GREY "\033[1;30m"

// ----------MESSAGES
#define BAD_INPUT "program must take in at least two arguments."

/* ---------------------UTILS FUNCTIONS */
void			printList(std::list<int> l, const char *color);
bool			listIsSorted(std::list<int> l);
bool			isListMin(std::list<int> main, int ref);
void			pushFirstElementToFront(std::list<int> &main, std::list<int> &aux);
void			displayNbBeforeOrdering(char **argv);

/* ---------------------PMERGEME TEMPLATES */
template <typename Container>
Container	insertStruggler(Container &aux, int ref)
{
	for (typename Container::iterator itAux = aux.begin(); itAux != aux.end(); ++itAux)
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

template <typename Container>
Container	mergedSortedList(Container &main,Container &aux, long unsigned int index, const long unsigned int originalSize)
{
	typename Container::iterator	itMain = main.begin();
	typename Container::iterator	itAux = aux.begin();

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
		return (mergedSortedList<Container>(main, aux, index + 1, originalSize));
}

template <typename Container>
Container	sortEachPair(Container main, Container aux)
{
	typename Container::iterator	it1 = main.begin();
	typename Container::iterator	nextIt1 = main.begin();
	typename Container::iterator	it2 = aux.begin();
	typename Container::iterator	nextIt2 = aux.begin();

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

template <typename T>
void	fordJohnsonSort(T main)
{
	T				aux;
	int							struggler;
	typename T::iterator it;
	int							originalSize = main.size();
	int							originalSizeWithoutStruggler = main.size() - (main.size() % 2);

	if (main.size() < 2)
		return ;

	if (main.size() % 2 == 1)
	{
		it = main.end();
		--it;
		struggler = *it;
		main.erase(it);
	}
	it = main.begin();
	while (aux.size() < main.size() && it != main.end())
	{
		typename T::iterator next_it = it;
		++next_it;
		if (next_it != main.end() && *it > *next_it)
		{
			std::iter_swap(it, next_it);
		}
		aux.push_back(*next_it);
		it = main.erase(next_it);
	}
	
	fordJohnsonSort<T>(main);
	fordJohnsonSort<T>(aux);

	aux = sortEachPair<T>(main, aux);
	pushFirstElementToFront(main, aux);
	aux = mergedSortedList<T>(main, aux, 0, originalSizeWithoutStruggler);
	if (originalSize % 2 == 1)
		aux = insertStruggler(aux, struggler);
}

template <typename T>
T convertDataInputIntoList(char **argv, int argc)
{
    T input;
    int value;

    for (int i = 1; i < argc; i++)
    {
        for (int j = 0; argv[i][j]; j++)
        {
            if (!isdigit(argv[i][j]))
                throw std::out_of_range("Invalid input.");
        }
        std::istringstream iss(argv[i]);
        iss >> value;
        input.push_back(value);
    }
    return input;
}

#endif