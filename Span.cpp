/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 13:40:28 by blarger           #+#    #+#             */
/*   Updated: 2024/06/24 13:53:13 by blarger          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Span.hpp"

/* --------------CONSTRUCTORS */
Span::Span(unsigned int _maxIntStockable) : maxIntStockable(_maxIntStockable)
{}

Span::Span() : maxIntStockable(10)
{}

/* --------------DECONSTRUCTORS */
Span::~Span(void)
{
	std::cout << RED << "Span deconstructor called!" << RESET << std::endl;
}

/* --------------COPY */
Span::Span(const Span& other) : maxIntStockable(other.maxIntStockable)
{
    std::cout << GREEN << "Span calling copy assignment!" << RESET << std::endl;
}

/* --------------OPERATORS */
std::ostream &operator<<(std::ostream &os, const Span &f)
{
	os << "Span maximum integer stockable is " << f.getMaxmaxIntStockable();
	return (os);
}

Span 		&Span::operator=(const Span &F)
{
	this->maxIntStockable = F.maxIntStockable;
	return (*this);
}

/* --------------GETTER */
unsigned int				Span::getMaxmaxIntStockable(void) const {return (this->maxIntStockable);}

/* --------------SETTER */


/* --------------FUNCTION MEMBER */


// ************************************************************************** //
//                               Container                                		  //
// ************************************************************************** //


void			Span::addNumber(int n)
{
	try
	{
		std::cout << "size = " << this->vector.size() << "max limit = " << this->maxIntStockable << std::endl;
		if (this->vector.size() + 1 >= this->maxIntStockable)
			throw std::out_of_range("Max storage limit reached");
	}
	catch(const std::out_of_range& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	
	this->vector.push_back(n);
}

void			Span::addRandomNumbers(int index)
{
	int	randomNumber;

	for (int i = 0; i < index; i++)
	{
		randomNumber = rand() % 100000;
		this->vector.push_back(randomNumber);
	}
}