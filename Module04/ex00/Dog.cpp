/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:20:13 by blarger           #+#    #+#             */
/*   Updated: 2024/06/11 10:09:53 by blarger          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Animal.hpp"

/* --------------CONSTRUCTORS */
Dog::Dog(std::string _type) : Animal(_type)	
{
	std::cout << GREEN << "Dog constructor called. Setting type to " << _type << RESET << std::endl;
}

Dog::Dog() : Animal("Dog")
{
	std::cout << GREEN << "Dog constructor called. Setting type to " << this->getType() << RESET << std::endl;

}

/* --------------DECONSTRUCTORS */
Dog::~Dog(void)
{
	std::cout << RED << "Dog deconstructor called!" << RESET << std::endl;
}

/* --------------COPY */
Dog::Dog(const Dog& other) : Animal("Dog")
{
	(void)other;
    std::cout << GREEN << "Dog calling copy assignment!" << RESET << std::endl;
}

/* FUNCTION */
void Dog::makeSound( void ) const {std::cout << "Warf!" << std::endl;}
