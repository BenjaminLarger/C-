/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 21:06:56 by blarger           #+#    #+#             */
/*   Updated: 2024/06/12 21:08:54 by blarger          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Materia.hpp"

/* --------------CONSTRUCTORS */
ICharacter::ICharacter()
{
	std::cout << GREEN << "ICharacter constructor called. Setting type to " << this->type << RESET << std::endl;
}

/* --------------DECONSTRUCTORS */
ICharacter::~ICharacter(void)
{
	std::cout << RED << "ICharacter deconstructor called!" << RESET << std::endl;
}

/* --------------COPY */
ICharacter::ICharacter(const ICharacter& other)
{
	this->type = other.type;
	std::cout << GREEN << "ICharacter calling copy assignment!" << RESET << std::endl;
}


/* GETTER */
AMateria* ICharacter::clone() const
{
	AMateria	*_clone = new ICharacter(*this);
}