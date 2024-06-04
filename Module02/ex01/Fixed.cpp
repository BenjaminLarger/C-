/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 06:47:36 by blarger           #+#    #+#             */
/*   Updated: 2024/06/04 18:48:11 by blarger          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Fixed.hpp"

const int Fixed::fractionalBits = 8;

/* --------------OVERLOADING ASSIGNMENT OPERATORS */

void Fixed::operator=(const Fixed &F)
{
	std::cout << BLUE << "Copy assignment operator called " << F.getRawBits() << RESET << std::endl;
	setRawBits(F.getRawBits());
}

std::ostream &operator<<(std::ostream &os, const Fixed &f)
{
	float	rawBits = f.toFloat();

	std::cout << " Copy assignment operator called" << std::endl;
	os << "Fixed object with raw bits: " << rawBits;
	
	return (os);
}

/* --------------CONSTRUCTORS */

Fixed::Fixed(const int n)/*  : fixedDecimal(n << fractionalBits) */
{
	std::cout << GREEN << "Int constructor called " << n;
	fixedDecimal = n << fractionalBits;
	std::cout << " fixed decimal " << fixedDecimal << RESET << std::endl;
}

Fixed::Fixed(const float n) /* : fixedDecimal(roundf(n * (1 << fractionalBits))) */
{
	std::cout << YELLOW << "Float constructor called " << n;
	fixedDecimal = roundf(n * (1 << fractionalBits));
	std::cout << YELLOW << " fixed decimal " << fixedDecimal << RESET << std::endl;

}

Fixed::Fixed(void)
{
	std::cout << "Default constructor called," << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	setRawBits(other.getRawBits());
}

/* --------------DECONSTRUCTORS */

Fixed::~Fixed(void)
{
	std::cout << RED << "Destructor called : " << this->getRawBits() << RESET << std::endl;
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