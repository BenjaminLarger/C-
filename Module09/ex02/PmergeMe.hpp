/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:51:44 by blarger           #+#    #+#             */
/*   Updated: 2024/06/29 14:50:42 by blarger          ###   ########.fr       */
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

// ************************************************************************** //
//                               Class                                		  //
// ************************************************************************** //


/* ---------------------UTILS FUNCTIONS */
void			printList(std::list<int> l, const char *color);
bool			listIsSorted(std::list<int> l);
bool			isListMin(std::list<int> main, int ref);
void			pushFirstElementToFront(std::list<int> &main, std::list<int> &aux);
//std::list<int>	convertDataInputIntoList(char **argv, int argc);
void			displayNbBeforeOrdering(char **argv);

/* ---------------------PMERGEME FUNCTIONS */
std::list<int>	sortEachPair(std::list<int> main, std::list<int> aux);
std::list<int>	mergedSortedList(std::list<int> &main,std::list<int> &aux, long unsigned int index, const long unsigned int originalSize);
std::list<int>	insertStruggler(std::list<int> &aux, int ref);
//void			fordJohnsonSort(std::list<int> main);


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

	aux = sortEachPair(main, aux);
	pushFirstElementToFront(main, aux);
	aux = mergedSortedList(main, aux, 0, originalSizeWithoutStruggler);
	if (originalSize % 2 == 1)
		aux = insertStruggler(aux, struggler);
}

#endif