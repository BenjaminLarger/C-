/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 18:20:22 by blarger           #+#    #+#             */
/*   Updated: 2024/06/20 19:24:46 by blarger          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "ShrubberyCreationForm.hpp"

/* --------------CONSTRUCTORS */
Shrubbery::Shrubbery(std::string _target) : AForm("Shrubbery", 145, 137), target(_target)
{
	//std::cout << GREEN << "President constructor called setting target to " << target << RESET << std::endl;
}

Shrubbery::Shrubbery() : AForm("Shrubbery", 145, 137), target("Shrubbery")
{
	//std::cout << GREEN << "President constructor called setting target to " << target << RESET << std::endl;
}

/* --------------DECONSTRUCTORS */
Shrubbery::~Shrubbery(void)
{
	//std::cout << RED << "Shrubbery deconstructor called!" << RESET << std::endl;
}

/* --------------OPERATORS */
Shrubbery 		&Shrubbery::operator=(const Shrubbery &F)
{
	this->target = F.target;
	return (*this);
}

/* --------------COPY */
Shrubbery::Shrubbery(const Shrubbery& other) : AForm(other), target(other.target)
{
    std::cout << GREEN << "Shrubbery calling copy assignment!" << RESET << std::endl;
}

/* --------------GETTER */
std::string		Shrubbery::getTarget(void) const { return (this->target); }

/* --------------MEMBER */
bool 			Shrubbery::execute(Bureaucrat const &executor) const
{
	if (AForm::checkRequirement(137, executor) == true && this->getIsSigned() == true)
	{
			std::ofstream ofs((this->getTarget() + "_shrubbery").c_str());

			if (!ofs)
			{
				std::cout << RED << "Error opening file" << RESET << std::endl;
                return (false);
            }
            ofs << "  ccee88oo\n"
                "C8O8O8Q8PoOb\n"
                "OBObUOOy\n"
                "cOB8OqOOpPc\n"
                "  6OuU\\\\/\n"  // Changed here
                "      ||\n"
                "      //\n"
                "     //\n"
                "     \\|\n";
            ofs.close();
            return (true);
    }
    return (false);
}
