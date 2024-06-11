/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:20:13 by blarger           #+#    #+#             */
/*   Updated: 2024/06/11 17:33:21 by blarger          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Animal.hpp"

/* --------------CONSTRUCTORS */
Dog::Dog(std::string _type) : AAnimal(_type)	
{
	std::cout << BLUE << "Dog constructor called. Setting type to " << _type << RESET << std::endl;
	this->idea = new Brain();
}

Dog::Dog() : AAnimal("Dog")
{
	std::cout << BLUE << "Dog constructor called. Setting type to " << this->getType() << RESET << std::endl;
	this->idea = new Brain();
}

/* --------------DECONSTRUCTORS */
Dog::~Dog(void)
{
	delete this->idea;
	std::cout << DARK_RED << "Dog deconstructor called!" << RESET << std::endl;
}

/* --------------COPY */
Dog::Dog(const Dog& other) : AAnimal("Dog")
{
    std::cout << GREEN << "Dog calling copy assignment!" << RESET << std::endl;
	if (other.idea)
	{
		idea = new Brain(*other.idea);
	}
	else
		idea=NULL;
}

/* FUNCTION */
void Dog::makeSound( void ) const {std::cout << "Warf!" << std::endl;}
