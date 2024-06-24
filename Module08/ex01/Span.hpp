/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:14:46 by blarger           #+#    #+#             */
/*   Updated: 2024/06/24 13:34:15 by blarger          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#pragma once
#ifndef EASYFIND_HPP
#define EASYFIND_HPP

// ----------INCLUDE
#include <iostream>
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <stdexcept>

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


// ************************************************************************** //
//                               Class                                		  //
// ************************************************************************** //

class Span {

private:
	unsigned int		maxIntStockable;
	std::vector<int> 	vector;
	
public:
	Span();
	Span(unsigned int _maxIntStockable);
	Span(const Span& other);
	~Span(void);

	unsigned int		getMaxmaxIntStockable(void) const;

	Span	&operator=(const Span &other);

	void	addNumber(int numerToAdd);
	void	addRandomNumbers(int indexToAdd);
	int		shortestSpan(void);
	int		longestSpan(void);
};


#endif
