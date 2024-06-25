/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:14:46 by blarger           #+#    #+#             */
/*   Updated: 2024/06/25 17:13:41 by blarger          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/


//https://www.geeksforgeeks.org/stack-in-cpp-stl/

#pragma once
#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

// ----------INCLUDE
#include <iostream>
#include <stack>
#include <deque>
#include <vector>


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
//                               Class Template                                		  //
// ************************************************************************** //

template <typename T, class container = std::deque<T> >
class MutantStack : public std::stack<T, container>
{
	public:
		MutantStack() {};
		~MutantStack() {};
		MutantStack(const MutantStack &stack) {*this = stack;}

		MutantStack 		&operator=(const MutantStack &F) {return (*this);}

		typedef	typename container::iterator	iterator;
		iterator begin()
		{
			return (this->c.begin());
		}
		iterator	end()
		{
			return (this->c.end());
		}
};

#endif