/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 16:26:24 by blarger           #+#    #+#             */
/*   Updated: 2024/06/04 09:03:34 by blarger          ###   ########.fr       */
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

// ----------DEFINITION

// ----------COLORS
#define RESET   "\033[0m"
#define BLACK   "\033[30m"
#define RED     "\033[1;31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[1; 37m"

// ************************************************************************** //
//                               Class                                //
// ************************************************************************** //

class Fixed {

private:
	int			fixedDecimal;
	static int	fractionalBits;

public:
	Fixed(void);
	Fixed(const Fixed& other);
	~Fixed (void);
	int			getRawBits(void) const;
	void		setRawBits(int const raw);
	void		operator=(const Fixed& F);
};

// ----------FUNCTIONS

/* INFILE */
void		openInfile(char *infile, std::ifstream& infile_fd);
std::string	readInfile(std::ifstream& infile_fd, std::string line);

/* OUTFILE */
void		createNewFile(char *infile, std::ifstream& infile_fd, std::ofstream& outfile_fd);
std::string	sedNewLine(std::string fileContent, const char *s1, const char *s2);

#endif