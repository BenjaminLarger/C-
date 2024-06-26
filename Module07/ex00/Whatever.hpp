/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:14:46 by blarger           #+#    #+#             */
/*   Updated: 2024/07/01 09:50:47 by blarger          ###   ########.fr       */
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
//                               Template                                		  //
// ************************************************************************** //

template	<typename T> void swap(T &x, T &y)
{
	T	temp;
	
	temp = x;
	x = y;
	y = temp;
}

template	<typename T> T min(const T &x, const T &y)
{
	return (y <= x) ? y : x;
}

template	<typename T> T max(const T &x, const T &y)
{
	return (y >= x) ? y : x;
}

// ************************************************************************** //
//                               Class                                		  //
// ************************************************************************** //

/* class Point {
public:
    int x, y;

    Point() : x(0), y(0) {}
    Point(int x, int y) : x(x), y(y) {}

    bool operator<=(const Point& other) const {
        return x * x + y * y <= other.x * other.x + other.y * other.y;
    }

    bool operator>=(const Point& other) const {
        return x * x + y * y >= other.x * other.x + other.y * other.y;
    }
}; */
#endif