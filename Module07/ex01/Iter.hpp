/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:14:46 by blarger           #+#    #+#             */
/*   Updated: 2024/07/01 09:51:03 by blarger          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#pragma once
#ifndef WHATEVER_HPP
#define WHATEVER_HPP

// ----------INCLUDE
#include <iostream>
#include <exception>

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

template <typename T> class Array
{
	private:
		T* ptr;
		int size;

	public:
		Array(T arr[], int s);
		void print();
};


// ************************************************************************** //
//                               Template                                		  //
// ************************************************************************** //

template	<typename T, typename FUNC>
void iter(T *arr, const int arrayLength, void (*f)(FUNC &element)) 
{
	for (int i = 0; i < arrayLength; i++)
	{
		f(arr[i]);
	}
}

template	<typename T>
void	print(T &i)
{
	std::cout << YELLOW << i << RESET << std::endl;
}

#endif