/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 20:33:38 by blarger           #+#    #+#             */
/*   Updated: 2024/06/12 20:56:45 by blarger          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Materia.hpp"

/* --------------CONSTRUCTORS */
Ice::Ice(std::string const & type)
{
	this->type = type;
	std::cout << GREEN << "Ice constructor called. Setting type to " << type << RESET << std::endl;
}

Ice::Ice()
{
	this->type= "ice";
	std::cout << GREEN << "Ice constructor called. Setting type to " << this->type << RESET << std::endl;
}

/* --------------DECONSTRUCTORS */
Ice::~Ice(void)
{
	std::cout << RED << "Ice deconstructor called!" << RESET << std::endl;
}

/* --------------COPY */
Ice::Ice(const Ice& other)
{
	this->type = other.type;
	std::cout << GREEN << "Ice calling copy assignment!" << RESET << std::endl;
}


/* GETTER */
AMateria* Ice::clone() const
{
	AMateria	*_clone = new Ice(*this);
}