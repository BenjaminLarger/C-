/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:19:54 by blarger           #+#    #+#             */
/*   Updated: 2024/06/11 12:07:03 by blarger          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Animal.hpp"

/* --------------CONSTRUCTORS */
AAnimal::AAnimal(std::string _type) : type(_type)
{
	std::cout << GREEN << "AAnimal constructor called. Setting type to " << _type << RESET << std::endl;
}

AAnimal::AAnimal() : type("N/A")
{
	std::cout << GREEN << "AAnimal constructor called. Setting type to " << this->type << RESET << std::endl;
}

/* --------------DECONSTRUCTORS */
AAnimal::~AAnimal(void)
{
	std::cout << RED << "AAnimal deconstructor called!" << RESET << std::endl;
}

/* --------------COPY */
AAnimal::AAnimal(const AAnimal& other) : type(other.type)
{
    std::cout << GREEN << "AAnimal calling copy assignment!" << RESET << std::endl;
}

void AAnimal::makeSound( void ) const {std::cout << "<AAnimal sound>" << std::endl;}


/* GETTER */
std::string		AAnimal::getType(void) const {return (this->type);}
