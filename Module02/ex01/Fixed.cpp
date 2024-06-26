/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 06:47:36 by blarger           #+#    #+#             */
/*   Updated: 2024/06/05 17:00:46 by blarger          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Fixed.hpp"

const int Fixed::fractionalBits = 8;

/* --------------OVERLOADING ASSIGNMENT OPERATORS */

Fixed &Fixed::operator=(const Fixed &F)
{
	std::cout <<  "Copy assignment operator called" << std::endl;
	setRawBits(F.getRawBits());
	return (*this);
}
std::ostream&			operator<<(std::ostream& os, const Fixed& f)
{
	float	rawBits = f.toFloat();

	os << rawBits;
	return (os);
}

/* --------------CONSTRUCTORS */

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int n) : fixedDecimal(n << fractionalBits)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float n) : fixedDecimal(roundf(n * (1 << fractionalBits)))
{
	std::cout << "Float constructor called" << std::endl ;
}

Fixed::Fixed(const Fixed& other) : fixedDecimal(other.fixedDecimal)
{
	std::cout << "Copy constructor called" << std::endl;
	operator=(other);
}

/* --------------DECONSTRUCTORS */

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

/* --------------MEMBER FUNCTION */
int Fixed::getRawBits(void) const
{
	return (this->fixedDecimal);
}

void Fixed::setRawBits(int const raw)
{
	this->fixedDecimal = raw;
}

float Fixed::toFloat(void) const
{
	float floatValue = (float)getRawBits() / (1 << fractionalBits);
    return floatValue;
}

int Fixed::toInt(void) const
{
	int integerPart = getRawBits() >> fractionalBits;
	return (integerPart);
}
