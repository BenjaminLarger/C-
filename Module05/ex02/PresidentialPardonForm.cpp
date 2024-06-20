/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 18:21:18 by blarger           #+#    #+#             */
/*   Updated: 2024/06/20 17:39:23 by blarger          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "PresidentialPardonForm.hpp"

/* --------------CONSTRUCTORS */
President::President(std::string _target) : AForm("Robotomy", 25, 5), target(_target)
{
	std::cout << GREEN << "President constructor called setting target to " << target << RESET << std::endl;
}

President::President() : AForm("Robotomy", 25, 5), target("President")
{
	std::cout << GREEN << "President constructor called setting target to " << target << RESET << std::endl;}

/* --------------DECONSTRUCTORS */
President::~President(void)
{
	std::cout << RED << "President deconstructor called!" << RESET << std::endl;
}

/* --------------OPERATORS */
President 		&President::operator=(const President &F)
{
	this->target = F.target;
	return (*this);
}

/* --------------COPY */
President::President(const President& other) : AForm(other), target(other.target)
{
    std::cout << GREEN << "President calling copy assignment!" << RESET << std::endl;
}

/* --------------GETTER */
std::string		President::getTarget(void) const { return (this->target); }

/* --------------MEMBER */
bool 			President::execute(Bureaucrat const &executor) const
{
	if (AForm::checkRequirement(5, executor) == true && this->getIsSigned() == true)
	{
		std::cout << YELLOW << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << RESET << std::endl;
		return (true);	
	}
	return (false);
}
