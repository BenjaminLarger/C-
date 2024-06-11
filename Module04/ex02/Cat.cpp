/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:20:08 by blarger           #+#    #+#             */
/*   Updated: 2024/06/11 17:33:14 by blarger          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Animal.hpp"

/* --------------CONSTRUCTORS */
Cat::Cat(std::string _type) : AAnimal(_type)
{
	std::cout << CYAN << "Cat constructor called. Setting type to " << _type << RESET << std::endl;
	this->idea = new Brain();
}

Cat::Cat() : AAnimal("Cat")
{
	std::cout << CYAN << "Cat constructor called. Setting type to " << this->getType() << RESET << std::endl;
	this->idea = new Brain();

}

/* --------------DECONSTRUCTORS */
Cat::~Cat(void)
{
	delete this->idea;
	std::cout << GREY << "Cat deconstructor called!" << RESET << std::endl;
}

/* --------------COPY */
Cat::Cat(const Cat& other) : AAnimal("Cat")
{
    std::cout << GREEN << "Cat calling copy assignment!" << RESET << std::endl;
	if (other.idea)
	{
		idea = new Brain(*other.idea);
	}
	else
		idea=NULL;
}


/* FUNCTIONS */
void Cat::makeSound( void ) const {std::cout << "Meow!" << std::endl;}