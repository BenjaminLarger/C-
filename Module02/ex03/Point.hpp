/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 16:26:24 by blarger           #+#    #+#             */
/*   Updated: 2024/06/10 17:27:07 by blarger          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#pragma once
#ifndef POINT_HPP
#define POINT_HPP

// ----------INCLUDE
#include "Fixed.hpp"
#include <limits>

// ************************************************************************** //
//                               Class                                		  //
// ************************************************************************** //

class Point {

private:
	const Fixed		x;
	const Fixed		y;
	
public:
	Point();
	Point(const float _x, const float _y);
	Point(const Point& other);
	~Point (void);

	const Fixed&	getX() const;
	const Fixed&	getY() const;
	void			setX() const;
	void			setY() const;
	Point 			prompt_triangle_coordinates(char pointName);
	const Point		&operator=(const Point &other);
};

// ----------FUNCTION
bool	bsp( Point const a, Point const b, Point const c, Point const point);
float	crossProduct(Point p, Point a, Point b);
Point 	prompt_triangle_coordinates(std::string pointName, std::string color);

#endif