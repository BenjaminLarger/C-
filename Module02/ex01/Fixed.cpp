/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 06:47:36 by blarger           #+#    #+#             */
/*   Updated: 2024/06/04 09:32:36 by blarger          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Fixed.hpp"

const int	Fixed::fractionalBits = 8;

/* --------------OVERLOADING ASSIGNMENT OPERATORS */

void		Fixed::operator=(const Fixed& F)
{
		std::cout << "Copy assignment operator called" << std::endl;
		setRawBits(F.getRawBits());
}

void		Fixed::operator<<(const Fixed& F)
{
		std::cout << "Copy assignment operator called" << std::endl;
		setRawBits(F.getRawBits());
}


/* --------------CONSTRUCTORS */

Fixed::Fixed(const int n) : fixedDecimal(n)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float n) : fixedDecimal(n)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(void) : fixedDecimal(0)
{
	std::cout << "Default constructor called" << std::endl;
}

/* Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	setRawBits(other.getRawBits());
} */

/* --------------DECONSTRUCTORS */

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

/* --------------MEMBER FUNCTION */
int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->fixedDecimal);
}

void	Fixed::setRawBits(int const raw)
{
	this->fixedDecimal = raw;
}

float		Fixed::toFloat( void ) const
{
	
}

int			Fixed::toInt( void ) const
{
	
}