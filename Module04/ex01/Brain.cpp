/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 15:19:57 by blarger           #+#    #+#             */
/*   Updated: 2024/06/18 18:36:56 by blarger          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Animal.hpp"

/* --------------CONSTRUCTORS */
Brain::Brain(std::string _type)
{
	(void)_type;
	this->idea = new std::string[100];
	std::cout << MAGENTA << "Brain constructor called." << RESET << std::endl;
}

Brain::Brain()
{
	this->idea = new std::string[100];
	std::cout << MAGENTA << "Brain constructor called."  << RESET << std::endl;
	
}

/* --------------DECONSTRUCTORS */
Brain::~Brain(void)
{
	std::cout << ORANGE << "Brain deconstructor called!" << RESET << std::endl;
	delete[] this->idea;
}

/* --------------COPY */
Brain::Brain(const Brain& other) /*: type(other.type) */
{
    this->idea = new std::string[100];
	for (int i = 0; i < 100; ++i)
	{
        this->idea[i] = other.idea[i];
    }
    std::cout << GREEN << "Brain calling copy assignment!" << RESET << std::endl;
}

