/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:19:54 by blarger           #+#    #+#             */
/*   Updated: 2024/06/11 12:07:03 by blarger          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Bureaucrat.hpp"

/* --------------CONSTRUCTORS */
Bureaucrat::Bureaucrat(std::string _name, int _grade) : name(_name), grade(_grade)
{
	std::cout << GREEN << "Bureaucrat constructor called. Setting type to " << grade << "and name to " << name << RESET << std::endl;
}

Bureaucrat::Bureaucrat(std::string _name) : name(_name), grade(1)
{
	std::cout << GREEN << "Bureaucrat constructor called. Setting type to " << grade << "and name to " << name << RESET << std::endl;
}

Bureaucrat::Bureaucrat() : name("N/A"), grade(1)
{
	std::cout << GREEN << "Bureaucrat constructor called. Setting type to " << grade << "and name to " << name << RESET << std::endl;
}

/* --------------DECONSTRUCTORS */
Bureaucrat::~Bureaucrat(void)
{
	std::cout << RED << "Bureaucrat deconstructor called!" << RESET << std::endl;
}

/* --------------COPY */
Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name), grade(other.grade)
{
    std::cout << GREEN << "Bureaucrat calling copy assignment!" << RESET << std::endl;
}

/* GETTER */
int				Bureaucrat::getGrade(void) const {return (this->grade);}
std::string		Bureaucrat::getName(void) const {return (this->name);}

/* FUNCTION MEMBER */
/* Bureaucrat				&Bureaucrat::operator++()
{
	float	new_value;

	new_value = this->toFloat() + ϵ;
	new_value = (roundf(new_value * (1 << fractionalBits)));
	this->setRawBits(new_value);
	return (*this);
}

Bureaucrat				&Bureaucrat::operator--()
{
	float	new_value;

	new_value = this->toFloat() + ϵ;
	new_value = (roundf(new_value * (1 << fractionalBits)));
	this->setRawBits(new_value);
	return (*this);
} */

void		decrementGrade(Bureaucrat _bureaucrat)
{

}
void		incrementGrade(Bureaucrat _bureaucrat){}