/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 11:47:47 by blarger           #+#    #+#             */
/*   Updated: 2024/06/10 17:26:19 by blarger          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Point.hpp"

/* CONSTRUCTOR */
Point::Point() : x(0), y(0) {};
Point::Point(const float _x, const float _y) : x(_x), y(_y) {};
Point::Point(const Point& other) : x(other.x), y(other.y) {};
Point::~Point (void) {};

const Fixed&	Point::getX() const
{
	return (x);
}

const Fixed&	Point::getY() const
{
	return (y);
}

const Point 	&Point::operator=(const Point& other) {
    if (this != &other) {
		(Fixed) x = other.getX();
        (Fixed) y = other.getY();
    }
    return *this;
}

float	crossProduct(Point p, Point a, Point b)
{
return ((a.getX().toFloat() - p.getX().toFloat()) * (b.getY().toFloat() - p.getY().toFloat()) 
            - (a.getY().toFloat() - p.getY().toFloat()) * (b.getX().toFloat() - p.getX().toFloat()));
}


bool	bsp( Point const a, Point const b, Point const c, Point const point)
{
	float	d1, d2, d3;
	bool		has_neg, has_pos;
	
	d1 = crossProduct(point, a, b);
	d2 = crossProduct(point, b, c);
	d3 = crossProduct(point, c, a);

	std::cout << ORANGE << "crossProduct(point, a, b) = " << d1 << RESET << std::endl;
	if (d1 == 0)
		std::cout << RED <<  "p is on the b-a vector"  << RESET << std::endl;
	else if (d1 <= 0)
		std::cout << MAGENTA << "p is to the right of the b-a vector"<< RESET << std::endl;
	else
		std::cout << ORANGE << "p is to the left of the b-a vector" << RESET << std::endl;
	std::cout << BLUE << "-------------------------------" << RESET << std::endl;

	std::cout << ORANGE << "crossProduct(point, a, b) = " << d1 << RESET << std::endl;
	if (d2 == 0)
		std::cout << RED << "p is on the c-b vector line" << RESET << std::endl;
	else if (d1 <= 0)
		std::cout << MAGENTA << "p is at right of c-b vector" << RESET << std::endl;
	else
		std::cout << ORANGE << "p is at left of c-b vector" << RESET << std::endl;
	std::cout << BLUE << "-------------------------------" << RESET << std::endl;

	if (d3 == 0)
		std::cout << RED << "p is on the a-c vector line" << RESET << std::endl;
	else if (d1 <= 0)
		std::cout << MAGENTA << "p is at right of a-c vector" << RESET << std::endl;
	else
		std::cout << ORANGE << "p is at left of a-c vector" << RESET << std::endl;
	std::cout << BLUE << "-------------------------------" << RESET << std::endl;

	if (d1 == 0 || d2 == 0 || d3 == 0)
		return (false);
	
	has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
	has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);
	return !(has_neg && has_pos);
}
