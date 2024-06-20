/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 18:20:55 by blarger           #+#    #+#             */
/*   Updated: 2024/06/20 17:42:23 by blarger          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "RobotomyRequestForm.hpp"

/* --------------CONSTRUCTORS */
Robotomy::Robotomy(std::string _target) : AForm("Robotomy", 72, 45), target(_target)
{
	this->callIndex = 0;
	this->isRandomized = false;

	std::cout << GREEN << "President constructor called setting target to " << target << RESET << std::endl;
}

Robotomy::Robotomy() : AForm("Robotomy", 72, 45), target("Robotomy")
{
	this->callIndex = 0;
	this->isRandomized = false;

	std::cout << GREEN << "President constructor called setting target to " << target << RESET << std::endl;
}

/* --------------DECONSTRUCTORS */
Robotomy::~Robotomy(void)
{
	std::cout << RED << "Robotomy deconstructor called!" << RESET << std::endl;
}

/* --------------OPERATORS */
Robotomy 		&Robotomy::operator=(const Robotomy &F)
{
	this->target = F.target;
	return (*this);
}

/* --------------COPY */
Robotomy::Robotomy(const Robotomy& other) : AForm(other), target(other.target)
{
    std::cout << GREEN << "Robotomy calling copy assignment!" << RESET << std::endl;
}

/* --------------GETTER */
std::string		Robotomy::getTarget(void) const { return (this->target); }
int				Robotomy::getCallIndex(void) const { return (this->callIndex); }

/* --------------MEMBER */
bool 			Robotomy::execute(Bureaucrat const &executor) const
{
	if (AForm::checkRequirement(45, executor) == true && this->getIsSigned() == true)
	{
		std::cout << YELLOW << "<Some drilling noises>" << RESET << std::endl;
		if (rand() % 2 == 0)
		{
			std::cout << YELLOW << this->target << " has been randomized." << RESET << std::endl;
		}
		return (true);
	}
	return (false);
}