/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:14:46 by blarger           #+#    #+#             */
/*   Updated: 2024/06/24 12:12:24 by blarger          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#pragma once
#ifndef EASYFIND_HPP
#define EASYFIND_HPP

// ----------INCLUDE
#include <iostream>
#include <list>
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
//                               Container                                		  //
// ************************************************************************** //

template	<typename T>
T&			easyfind(std::list<T> list, int toFind)
{
	typename	std::list<T>::iterator	it;

	for (it = list.begin(); it != list.end(); ++it)
	{
		if (toFind == static_cast<int>(*it))
			return (*it);
	}
	throw std::out_of_range(" does not belong to the list passed as parameter.");
}

#endif
