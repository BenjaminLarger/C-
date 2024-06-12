/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 20:34:08 by blarger           #+#    #+#             */
/*   Updated: 2024/06/12 20:56:18 by blarger          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Materia.hpp"

/* --------------CONSTRUCTORS */
Cure::Cure(std::string const & type)
{
	this->type = type;
	std::cout << GREEN << "Cure constructor called. Setting type to " << type << RESET << std::endl;
}

Cure::Cure()
{
	this->type= "Cure";
	std::cout << GREEN << "Cure constructor called. Setting type to " << this->type << RESET << std::endl;
}

/* --------------DECONSTRUCTORS */
Cure::~Cure(void)
{
	std::cout << RED << "Cure deconstructor called!" << RESET << std::endl;
}

/* --------------COPY */
Cure::Cure(const Cure& other)
{
	this->type = other.type;
    std::cout << GREEN << "Cure calling copy assignment!" << RESET << std::endl;
}


/* GETTER */
AMateria* Cure::clone() const
{
	AMateria	*_clone = new Cure(*this);
}