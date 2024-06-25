/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 13:40:28 by blarger           #+#    #+#             */
/*   Updated: 2024/06/25 16:00:20 by blarger          ###   ########.fr       */
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
	this->vector = other.vector;
    std::cout << GREEN << "Span calling copy assignment!" << RESET << std::endl;
}

/* --------------OPERATORS */
Span 		&Span::operator=(const Span &F)
{
	this->vector = F.vector;
	this->maxIntStockable = F.maxIntStockable;
	return (*this);
}

/* --------------GETTER */
unsigned int				Span::getMaxmaxIntStockable(void) const {return (this->maxIntStockable);}

/* --------------SETTER */


/* --------------FUNCTION MEMBER */

void			Span::addNumber(int n)
{
	try
	{
		if (this->vector.size() + 1 > this->maxIntStockable)
			throw std::out_of_range("Max storage limit reached");
		this->vector.push_back(n);
	}
	catch(const std::out_of_range& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
}

void			Span::addRandomNumbers(int index)
{
	int	randomNumber;

	std::cout << BLUE << "Randomizing " << index << " numbers...\n| ";
	for (int i = 0; i < index; i++)
	{
		std::cout << i << " = " << randomNumber << " | ";
		randomNumber = rand() % 100000;
		this->vector.push_back(randomNumber);
	}
	std::cout << RESET << std::endl;
}

static void	printVectors(std::vector<int> 	vector)
{
	
	for(std::vector<int>::const_iterator it = vector.begin(); it != vector.end(); ++it)
	{
 		std::cout << BLUE << *it << " | ";
		
	}
	std::cout << RESET << std::endl;
}

void	Span::insertNumbers(unsigned int position, int n, const int val)
{
	std::vector<int>::iterator it = this->vector.begin();

	try
	{
		if (position > this->vector.size())
			throw std::out_of_range("ERROR : insertNumbers : position bigger than vector size!");
		else if (this->vector.size() + n > this->maxIntStockable)
			throw std::out_of_range("ERROR : insertNumbers : total size bigger than vector max size!");
		for(unsigned int i = 0; i < position; i++)
		{
			++it;
		}
		this->vector.insert(it, n, val);
		printVectors(this->vector);
		std::cout << GREEN << "Vector insertion successfull!" << RESET << std::endl;
	}
	catch (const std::out_of_range& e)
	{
		std::cerr << RED << e.what() << RESET <<  std::endl;
	}
}

int		Span::shortestSpan(void) const
{
	int	shortestDistance = std::numeric_limits<int>::max();
	int	currentDistance;
	
	if (this->vector.size() < 2)
		throw std::out_of_range("The vector size is too low. Minimum two!");
	
    for(std::vector<int>::const_iterator it = this->vector.begin(); it != this->vector.end() - 1; ++it)
	{
    	currentDistance = abs(*(it + 1) - *it);
		if (currentDistance < shortestDistance)
			shortestDistance = currentDistance;
	}
	
	return (shortestDistance);
}

int		Span::longestSpan(void) const
{
	int	largestDistance = std::numeric_limits<int>::min();
	int	currentDistance;
	
	if (this->vector.size() < 2)
		throw std::out_of_range("The vector size is too low. Minimum two!");
	
    for(std::vector<int>::const_iterator it = this->vector.begin(); it != this->vector.end() - 1; ++it)
	{
    	currentDistance = abs(*(it + 1) - *it);
		if (currentDistance > largestDistance)
			largestDistance = currentDistance;
	}
	
	return (largestDistance);
}
