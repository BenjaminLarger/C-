/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:51:44 by blarger           #+#    #+#             */
/*   Updated: 2024/07/11 19:29:59 by blarger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef RPN_HPP
#define RPN_HPP

// ----------INCLUDE
#include <iostream>
#include <stack>
#include <sstream>
#include <string>


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
#define BAD_INPUT "program must take in one argument : ./RPN <numbers>"

// ************************************************************************** //
//                               Class                                		  //
// ************************************************************************** //

struct Date
{
	private:
	    unsigned int day;
    	unsigned int month;
	    unsigned int year;
		
	public:
		Date(unsigned int d, unsigned int m, unsigned int y);
		Date();
		~Date();
		Date(const Date &stack);
		Date 		&operator=(const Date &F);

		unsigned int	getDay() const ;
		unsigned int	getMonth() const ;
		unsigned int	getYear() const ;
};

#endif
