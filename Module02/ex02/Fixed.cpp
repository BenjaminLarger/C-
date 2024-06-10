/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 06:47:36 by blarger           #+#    #+#             */
/*   Updated: 2024/06/10 17:01:17 by blarger          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Fixed.hpp"

/* --------------STATIC MEMBER VARIABLE---------- */
const int Fixed::fractionalBits = 8;

/* ---------------------------------------------- */
/* ---------------------------------------------- */
/* --------------OVERLOADING ASSIGNMENT OPERATORS */
/* ---------------------------------------------- */
/* ---------------------------------------------- */

/* ---------------------------------------------- */
/* EQUALITY */
/* ---------------------------------------------- */

Fixed 		&Fixed::operator=(const Fixed &F)
{
	setRawBits(F.getRawBits());
	return (*this);
}
/* ---------------------------------------------- */
/* COMPARISON */
/* ---------------------------------------------- */

std::ostream &operator<<(std::ostream &os, const Fixed &f)
{
	float	rawBits = f.toFloat();

	os << rawBits;
	return (os);
}

bool	Fixed::operator>=(const Fixed &F)
{
	if (this->getRawBits() >= F.getRawBits())
		return (true);
	else
		return (false);
}

bool	Fixed::operator>(const Fixed &F)
{
	if (this->getRawBits() > F.getRawBits())
		return (true);
	else
		return (false);
}

bool	Fixed::operator!=(const Fixed &F)
{
	if (this->getRawBits() != F.getRawBits())
		return (true);
	else
		return (false);
}

bool	Fixed::operator==(const Fixed &F)
{
	if (this->getRawBits() == F.getRawBits())
		return (true);
	else
		return (false);
}

bool	Fixed::operator<=(const Fixed &F)
{
	if (this->getRawBits() <= F.getRawBits())
		return (true);
	else
		return (false);
}

bool	Fixed::operator<(const Fixed &F)
{
	if (this->getRawBits() < F.getRawBits())
		return (true);
	else
		return (false);
}

/* ---------------------------------------------- */
/* ARITHMETIC */
/* ---------------------------------------------- */

float	Fixed::operator*(const Fixed &F)
{
	float	factor;

	factor = this->toFloat() * F.toFloat();
	return (factor);
}

float	Fixed::operator/(const Fixed &F)
{
	float	quotient;

	if (F.toFloat() == 0)
	{
		std::cout << RED << "Error: cannot divide by 0! Exit." << RESET << std::endl;
		exit(EXIT_FAILURE);
	}
	quotient = this->toFloat() / F.toFloat();
	return (quotient);
}

float	Fixed::operator+(const Fixed &F)
{
	float	sum;

	sum = this->toFloat() + F.toFloat();
	return (sum);
}

float	Fixed::operator-(const Fixed &F)
{
	float	difference;

	difference = this->toFloat() - F.toFloat();
	return (difference);
}

/* ---------------------------------------------- */
/* INCREMENTATION & DECREMENTATION OPERATORS */
/* ---------------------------------------------- */

Fixed				&Fixed::operator++()
{
	float	new_value;

	new_value = this->toFloat() + ϵ;
	new_value = (roundf(new_value * (1 << fractionalBits)));
	this->setRawBits(new_value);
	return (*this);
}

Fixed				&Fixed::operator--()
{
	float	new_value;

	new_value = this->toFloat() + ϵ;
	new_value = (roundf(new_value * (1 << fractionalBits)));
	this->setRawBits(new_value);
	return (*this);
}

Fixed				Fixed::operator++(int n)
{
	Fixed original = operator=(*this);
	float	new_value = this->toFloat() + ϵ;
	new_value = (roundf(new_value * (1 << fractionalBits)));
	this->setRawBits(new_value);
	(void)n;
	return (original);
}

Fixed				Fixed::operator--(int n)
{
	Fixed original = operator=(*this);
	float	new_value = this->toFloat() - ϵ;
	new_value = (roundf(new_value * (1 << fractionalBits)));
	this->setRawBits(new_value);
	(void)n;
	return (original);
}

/* ---------------------------------------------- */
/* ---------------------------------------------- */
/* --------------CONSTRUCTORS */
/* ---------------------------------------------- */
/* ---------------------------------------------- */

Fixed::Fixed(void)
{
	this->setRawBits(0);
}

Fixed::Fixed(const int n) : fixedDecimal(n << fractionalBits)
{}

Fixed::Fixed(const float n) : fixedDecimal(roundf(n * (1 << fractionalBits)))
{}

Fixed::Fixed(const Fixed& other)
{
	setRawBits(other.getRawBits());
}

/* ---------------------------------------------- */
/* --------------DECONSTRUCTORS */
/* ---------------------------------------------- */

Fixed::~Fixed(void)
{}

/* ---------------------------------------------- */
/* ---------------------------------------------- */
/* --------------MEMBER FUNCTION */
/* ---------------------------------------------- */
/* ---------------------------------------------- */

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

/* ---------------------------------------------- */
/* MIN / MAX */
/* ---------------------------------------------- */

Fixed&			Fixed::min(Fixed& a, Fixed& b)
{
	return (a.getRawBits() < b.getRawBits()) ? a : b;
}

const Fixed&	Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a.getRawBits() < b.getRawBits()) ? a : b;
}

Fixed&		Fixed::max(Fixed& a, Fixed& b)
{
	return (a.getRawBits() > b.getRawBits()) ? a : b;
}

const Fixed& 	Fixed::max(const Fixed& a, const Fixed& b)
{
	return (a.getRawBits() > b.getRawBits()) ? a : b;
}
