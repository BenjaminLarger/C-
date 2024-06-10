/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:20:13 by blarger           #+#    #+#             */
/*   Updated: 2024/06/10 15:25:21 by blarger          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Animal.hpp"

/* --------------CONSTRUCTORS */
Animal::Animal(std::string _type) :
	Animal(_type)	
{
	std::cout << GREEN << "Animal constructor called. Setting type to " << _type << RESET << std::endl;
	this->type = _type;
}

Animal::Animal() :
	Animal("N/A")
{
	std::cout << GREEN << "Animal constructor called. Setting type to " << this->type << RESET << std::endl;

}

/* --------------DECONSTRUCTORS */
Animal::~Animal(void)
{
	std::cout << RED << "Animal deconstructor called!" << RESET << std::endl;
}

/* --------------COPY */
Animal::Animal(const Animal& other)
    : Animal(other.type)
{
    std::cout << GREEN << "Animal calling copy assignment!" << RESET << std::endl;
}