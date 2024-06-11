/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:19:54 by blarger           #+#    #+#             */
/*   Updated: 2024/06/11 12:07:03 by blarger          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Animal.hpp"

/* --------------CONSTRUCTORS */
Animal::Animal(std::string _type) : type(_type)
{
	std::cout << GREEN << "Animal constructor called. Setting type to " << _type << RESET << std::endl;
}

Animal::Animal() : type("N/A")
{
	std::cout << GREEN << "Animal constructor called. Setting type to " << this->type << RESET << std::endl;
}

/* --------------DECONSTRUCTORS */
Animal::~Animal(void)
{
	std::cout << RED << "Animal deconstructor called!" << RESET << std::endl;
}

/* --------------COPY */
Animal::Animal(const Animal& other) : type(other.type)
{
    std::cout << GREEN << "Animal calling copy assignment!" << RESET << std::endl;
}

void Animal::makeSound( void ) const {std::cout << "<animal sound>" << std::endl;}


/* GETTER */
std::string		Animal::getType(void) const {return (this->type);}
