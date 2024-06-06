/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 06:47:36 by blarger           #+#    #+#             */
/*   Updated: 2024/06/06 11:59:40 by blarger          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Fixed.hpp"

const int Fixed::fractionalBits = 8;

/* --------------OVERLOADING ASSIGNMENT OPERATORS */

Fixed 		&Fixed::operator=(const Fixed &F)
{
	std::cout << CYAN << "this " << F.getRawBits() << RESET << std::endl;
	setRawBits(F.getRawBits());
	std::cout << CYAN <<  "Copy assignment operator called " << this->getRawBits() << RESET << std::endl;
	return (*this);
}

std::ostream &operator<<(std::ostream &os, const Fixed &f)
{
	std::cout << GREEN << "get raw bits " << f.getRawBits() << std::endl;
	float	rawBits = f.toFloat();

	os << rawBits;
	return (os);
}

Fixed 		&Fixed::operator>=(const Fixed &F)
{
	(void) F;
	return (*this);
}

Fixed 		&Fixed::operator!=(const Fixed &F)
{
	(void) F;
	return (*this);
}

Fixed 		&Fixed::operator==(const Fixed &F)
{
	(void) F;
	return (*this);
}

Fixed 		&Fixed::operator<=(const Fixed &F)
{
	(void) F;
	return (*this);
}

Fixed 		Fixed::operator*(const Fixed &F)
{
	Fixed	result;

	float	factor;

	factor = this->toFloat() * F.toFloat();
	std::cout << YELLOW << this->toFloat() << " | " << F.toFloat() << " | " << factor << RESET << std::endl;
	factor = roundf(factor * (1 << fractionalBits));
	result.setRawBits(factor);
	std::cout << YELLOW << "return : " << factor << RESET << std::endl;
	return (result);
}

Fixed 		&Fixed::operator/(const Fixed &F)
{
	(void) F;
	return (*this);
}

Fixed 		&Fixed::operator+(const Fixed &F)
{
	(void) F;
	return (*this);
}

Fixed 		&Fixed::operator-(const Fixed &F)
{
	(void) F;
	return (*this);
}


Fixed				&Fixed::operator++()
{
	float	new_value;

	new_value = this->toFloat() + ϵ;
	setRawBits(new_value);
	std::cout << CYAN << "++a " << this->getRawBits() << RESET << std::endl;
	return (*this);
}

Fixed				&Fixed::operator--()
{
	return (*this);
}

Fixed				&Fixed::operator++(int n)
{
	std::cout << CYAN << "a++" << RESET << std::endl;
	(void)n;
	return (*this);
}

Fixed				&Fixed::operator--(int n)
{
	(void)n;
	return (*this);
}


/* --------------CONSTRUCTORS */

Fixed::Fixed(void)
{
	this->setRawBits(0);
	std::cout << GREEN << "Default constructor called " << this->getRawBits() << RESET << std::endl;
}

Fixed::Fixed(const int n) : fixedDecimal(n << fractionalBits)
{
	std::cout << YELLOW << "Int constructor called " << this->getRawBits() << RESET << std::endl;
}

Fixed::Fixed(const float n) : fixedDecimal(roundf(n * (1 << fractionalBits)))
{
	std::cout << YELLOW << "Float constructor called " << this->getRawBits() << RESET << std::endl ;
}

/* Fixed::Fixed(const Fixed& other) : fixedDecimal(other.fixedDecimal) //not called
{
	std::cout << CYAN << "Copy constructor called " << this->getRawBits() << RESET << std::endl;
	operator=(other);
	std::cout << CYAN << this->getRawBits() << RESET << std::endl;
} */

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	setRawBits(other.getRawBits());
}

/* --------------DECONSTRUCTORS */

Fixed::~Fixed(void)
{
	std::cout <<  RED << "Destructor called " << this->fixedDecimal << RESET << std::endl;
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

/* MIN / MAX */
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
