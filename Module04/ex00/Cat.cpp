/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:20:08 by blarger           #+#    #+#             */
/*   Updated: 2024/06/11 12:44:44 by blarger          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Animal.hpp"

/* --------------CONSTRUCTORS */
Cat::Cat(std::string _type) : Animal(_type)
{
	std::cout << GREEN << "Cat constructor called. Setting type to " << _type << RESET << std::endl;
}

Cat::Cat() : Animal("Cat")
{
	std::cout << GREEN << "Cat constructor called. Setting type to " << this->getType() << RESET << std::endl;

}

/* --------------DECONSTRUCTORS */
Cat::~Cat(void)
{
	std::cout << RED << "Cat deconstructor called!" << RESET << std::endl;
}

/* --------------COPY */
Cat::Cat(const Cat& other) : Animal("Cat")
{
	(void)other;
    std::cout << GREEN << "Cat calling copy assignment!" << RESET << std::endl;
}


/* FUNCTIONS */
void Cat::makeSound( void ) const {std::cout << "Meow!" << std::endl;}