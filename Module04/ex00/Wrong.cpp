/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Wrong.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 10:22:55 by blarger           #+#    #+#             */
/*   Updated: 2024/06/11 10:32:59 by blarger          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Animal.hpp"

/* --------------CONSTRUCTORS */
WrongAnimal::WrongAnimal(std::string _type) : type(_type)
{
	std::cout << GREEN << "WrongAnimal constructor called. Setting type to " << _type << RESET << std::endl;
}

WrongAnimal::WrongAnimal() : type("N/A")
{
	std::cout << GREEN << "WrongAnimal constructor called. Setting type to " << this->type << RESET << std::endl;
}

/* --------------DECONSTRUCTORS */
WrongAnimal::~WrongAnimal(void)
{
	std::cout << RED << "WrongAnimal deconstructor called!" << RESET << std::endl;
}

/* --------------COPY */
WrongAnimal::WrongAnimal(const WrongAnimal& other) : type(other.type)
{
    std::cout << GREEN << "WrongAnimal calling copy assignment!" << RESET << std::endl;
}

void WrongAnimal::makeSound( void ) const {std::cout <<  "<Wrong animal sound>" << std::endl;}


/* GETTER */
std::string		WrongAnimal::getType(void) const {return (this->type);}

/* ---------------------------------------------------------------------------- */
/* ---------------------------------------------------------------------------- */
/* ---------------------------------------------------------------------------- */
/* ---------------------------------------------------------------------------- */
/* ---------------------------------------------------------------------------- */

/* --------------CONSTRUCTORS */
WrongCat::WrongCat(std::string _type) : WrongAnimal(_type) //WrongCat(_type) ?
{
	std::cout << GREEN << "WrongCat constructor called. Setting type to " << _type << RESET << std::endl;
}

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << GREEN << "WrongCat constructor called. Setting type to " << this->getType() << RESET << std::endl;

}

/* --------------DECONSTRUCTORS */
WrongCat::~WrongCat(void)
{
	std::cout << RED << "WrongCat deconstructor called!" << RESET << std::endl;
}

/* --------------COPY */
WrongCat::WrongCat(const WrongCat& other) : WrongAnimal("WrongCat")
{
	(void)other;
    std::cout << GREEN << "WrongCat calling copy assignment!" << RESET << std::endl;
}


/* FUNCTIONS */
void WrongCat::makeSound( void ) const {std::cout << "Meow!" << std::endl;}