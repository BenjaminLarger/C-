/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:19:54 by blarger           #+#    #+#             */
/*   Updated: 2024/06/11 12:07:03 by blarger          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Materia.hpp"

/* --------------CONSTRUCTORS */
AMateria::AMateria(std::string const & type) : type(type)
{
	std::cout << GREEN << "AMateria constructor called. Setting type to " << type << RESET << std::endl;
}

AMateria::AMateria() : type("N/A")
{
	std::cout << GREEN << "AMateria constructor called. Setting type to " << this->type << RESET << std::endl;
}

/* --------------DECONSTRUCTORS */
AMateria::~AMateria(void)
{
	std::cout << RED << "AMateria deconstructor called!" << RESET << std::endl;
}

/* --------------COPY */
AMateria::AMateria(const AMateria& other) : type(other.type)
{
    std::cout << GREEN << "AMateria calling copy assignment!" << RESET << std::endl;
}


/* GETTER */
AMateria* AMateria::clone() const//to implement
{}