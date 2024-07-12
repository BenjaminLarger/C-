/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:51:44 by blarger           #+#    #+#             */
/*   Updated: 2024/07/12 09:29:34 by blarger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef RPN_HPP
#define RPN_HPP

// ---------------------INCLUDE
#include <algorithm>
#include <ctime>
#include <iostream>
#include <list>
#include <map>
#include <sstream>
#include <stack>
#include <string>

// ---------------------COLORS
#define RESET "\033[0m"
#define BLACK "\033[30m"
#define RED "\033[1;31m"
#define DARK_RED "\033[2;31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define ORANGE "\033[38;5;214m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[1; 37m"
#define GREY "\033[1;30m"

// ---------------------MESSAGES
#define BAD_INPUT "program must take in at least two arguments."

/* ---------------------UTILS FUNCTIONS */
void displayNbBeforeOrdering(char **argv);
void displayTimeToProcess(std::clock_t start, std::clock_t end,
                          std::string containerUsed);

template <typename Container>
void printContainer(Container l, const char *color) {
  for (typename Container::iterator it = l.begin(); it != l.end(); ++it) {
  }
}

template <typename Container>
void displayNbAfterOrdering(Container main, std::string colour) {
  if (colour == WHITE)
    std::cout << "After:	";
  for (typename Container::iterator itMain = main.begin(); itMain != main.end();++itMain)
	{
		std::cout << colour << *itMain << " ";
	}
  std::cout << RESET << std::endl;
}

template <typename Container> bool isListMin(Container main, int ref)
{
	if (main.size() == 1)
		return (true);
  for (typename Container::iterator itMain = main.begin(); itMain != main.end();
       ++itMain) {
    if (*itMain < ref)
      return (false);
  }
  return (true);
}

template <typename Container> bool listIsSorted(Container l) {
  for (typename Container::iterator it = l.begin(); it != l.end(); ++it) {
    typename Container::iterator next_it = it;
    ++next_it;
    if (next_it != l.end() && *it > *next_it)
	{
      return (false);
    }
  }
  return (true);
}

/* ---------------------PMERGEME TEMPLATES */
template <typename Container>
Container insertStruggler(Container &aux, int ref) {
  for (typename Container::iterator itAux = aux.begin(); itAux != aux.end();
       ++itAux) {
    if (*itAux == ref || ref < *itAux) {
      aux.insert(itAux, ref);

      return (aux);
    }
  }
  aux.push_back(ref);
  return (aux);
}

template<typename T>
bool shouldErase(const T& element)
{
    const T threshold = 10; // Example threshold
    return element < threshold;
}

template <typename Container>
Container mergedSortedList(Container main, Container &aux)
{
	typename Container::iterator itMain = main.begin(), itAux = aux.begin();
	Container	result;

	while (itMain != main.end() && main.size() != 0 && !main.empty())
	{
		if (isListMin<Container>(main, *itMain))
		{
			while (itAux != aux.end() && itMain != main.end() && !main.empty())
			{
				if (*itAux > *itMain)
				{
					aux.insert(itAux, *itMain);
					itMain = main.erase(itMain);
					if (main.empty() || main.size() == 0)
						return (aux);
					itAux = aux.begin();

				}
				else
				{
					++itAux;
				}

			}
		}
		else
			++itMain;
		if (itMain == main.end() && main.size() != 0)
			itMain = main.begin();
	}
	return (aux);
}

template <typename Container>
Container sortEachPair(Container main, Container aux) {
  typename Container::iterator it1 = main.begin();
  typename Container::iterator nextIt1 = main.begin();
  typename Container::iterator it2 = aux.begin();
  typename Container::iterator nextIt2 = aux.begin();

  ++nextIt2;
  ++nextIt1;

  while (nextIt2 != aux.end()) {
    if (*it2 > *nextIt2) {
      std::iter_swap(it2, nextIt2);
      std::iter_swap(it1, nextIt1);
    }
    ++it2;
    ++nextIt2;
    ++it1;
    ++nextIt1;
  }
  if (listIsSorted<Container>(aux) == true)
    return (aux);
  else
    return (sortEachPair(main, aux));
}

template <typename Container>
void fordJohnsonSort(Container main,
                     long unsigned int originalSizeWithoutStruggler,
                     bool printResult) {
  Container aux;
  int struggler;
  typename Container::iterator it;
  int originalSize = main.size();

  if (main.size() < 2)
    return;

  if (main.size() % 2 == 1) {
    it = main.end();
    --it;
    struggler = *it;
    main.erase(it);
  }
  it = main.begin();
  while (aux.size() < main.size() && it != main.end()) {
    typename Container::iterator next_it = it;
    ++next_it;
    if (next_it != main.end() && *it > *next_it) {
      std::iter_swap(it, next_it);
    }
    aux.push_back(*next_it);
    it = main.erase(next_it);
  }

  fordJohnsonSort<Container>(main, originalSizeWithoutStruggler, printResult);
  fordJohnsonSort<Container>(aux, originalSizeWithoutStruggler, printResult);

  if (aux.size() + main.size() != originalSizeWithoutStruggler)
    return;
  aux = sortEachPair<Container>(main, aux);
  mergedSortedList<Container>(main, aux);
  if (originalSize % 2 == 1)
    aux = insertStruggler(aux, struggler);
  if (printResult == true && listIsSorted(aux) == true) {
    displayNbAfterOrdering(aux, WHITE);
     std::cout << GREEN << "List is sorted !" << RESET << std::endl;
  } else if (printResult == true)
    std::cout << RED << "List is not sorted !" << RESET << std::endl;
}

template <typename Container>
Container convertDataInputIntoList(char **argv, int argc) {
  Container input;
  int value;

  for (int i = 1; i < argc; i++) {
    for (int j = 0; argv[i][j]; j++) {
      if (!isdigit(argv[i][j]))
	  {
        throw std::out_of_range("Invalid input.");
	  }
    }
    std::istringstream iss(argv[i]);
    iss >> value;
    input.push_back(value);
  }
  return input;
}

#endif