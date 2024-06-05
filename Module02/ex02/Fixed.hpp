/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 16:26:24 by blarger           #+#    #+#             */
/*   Updated: 2024/06/05 18:58:35 by blarger          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#pragma once
#ifndef FIXED_HPP
#define FIXED_HPP

// ----------INCLUDE

#include <fstream> 
#include <fstream> 
#include <iostream> 
#include <string>
#include <cstdlib>
#include <cstring>
#include <cmath>

// ----------DEFINITION

// ----------COLORS
#define RESET   "\033[0m"
#define BLACK   "\033[30m"
#define RED     "\033[1;31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define ORANGE "\033[38;5;214m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[1; 37m"

// ************************************************************************** //
//                               Class                                //
// ************************************************************************** //

class Fixed {

private:
	int					fixedDecimal;
	static const int	fractionalBits;

public:
	Fixed(void);
	Fixed(const Fixed& other);
	Fixed(const int n);
	Fixed(const float n);
	~Fixed (void);

	int					getRawBits(void) const;
	void				setRawBits(int const raw);
	float				toFloat( void ) const;
	int					toInt( void ) const;

	static Fixed&		min(Fixed& a, Fixed& b);
	static const Fixed&	min(const Fixed &a, const Fixed &b);
	static Fixed&		max(Fixed& a, Fixed& b);
    static const Fixed& max(const Fixed& a, const Fixed& b);

	Fixed				&operator=(const Fixed& F);
	Fixed				&operator>=(const Fixed& F);
	Fixed				&operator<=(const Fixed& F);
	Fixed				&operator==(const Fixed& F);
	Fixed				&operator!=(const Fixed& F);

	Fixed				&operator+(const Fixed& F);
	Fixed				&operator-(const Fixed& F);
	Fixed				operator*(const Fixed& F);
	Fixed				&operator/(const Fixed& F);

	Fixed				&operator++();
	Fixed				&operator--();
	Fixed				&operator++(int);
	Fixed				&operator--(int);
};

std::ostream&			operator<<(std::ostream& os, const Fixed& f);

// ----------FUNCTIONS



#endif