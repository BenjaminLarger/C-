/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:13:01 by blarger           #+#    #+#             */
/*   Updated: 2024/06/19 12:55:23 by blarger          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Form.hpp"

/* --------------CONSTRUCTORS */
Form::Form(std::string _name, int _minGradeToSign, int _minGradeToExecute) : name(_name), minGradeToSign(_minGradeToSign), minGradeToExecute(_minGradeToExecute), isSigned(false);
{
	try
	{
		if (_minGradeToSign < 1 || _minGradeToExecute < 1)
			throw GradeTooLowException();
		else if (_minGradeToSign > 150 || _minGradeToExecute > 150)
			throw GradeTooHighException();
		else
			std::cout << GREEN << "Form constructor called. Setting name to " << name << ", minimum grade to sign to " << _minGradeToSign << ", minimum grade to execute " << _minGradeToExecute << RESET << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << ORANGE << "An exception occurred: " << this->getName() << ". " << e.what() << RESET << std::endl;
	}
	catch (...)
	{
		std::cout << RED << "An unknown exception occurred." << RESET << std::endl;
	}
}

Form::Form() : name("Noname"), minGradeToSign(75), minGradeToExecute(10) , isSigned(false)
{
	std::cout << GREEN << "Form constructor called. Setting name to " << name << RESET << std::endl;
}

/* --------------DECONSTRUCTORS */
Form::~Form(void)
{
	std::cout << RED << "Form deconstructor called!" << RESET << std::endl;
}

/* --------------OPERATORS */
std::ostream&			operator<<(std::ostream& os, const Form& f)
{
	os << f.getName() << ", form minimum grade to sign " << f.getMinGradeToSign(), ", form minimum grade to execute ", f.getMinGradeToExecute();
	return (os);
}

/* --------------COPY */
Form::Form(const Form& other) : name(other.name), minGradeToSign(other.minGradeToSign), minGradeToExecute(other.minGradeToExecute)
{
    std::cout << GREEN << "Form calling copy assignment!" << RESET << std::endl;
}

/* --------------GETTER */
int				Form::getMinGradeToSign(void) const {return (this->minGradeToSign);}
int				Form::getMinGradeToExecute(void) const {return (this->minGradeToExecute);}
std::string		Form::getName(void) const {return (this->name);}

/* --------------SETTER */

/* --------------FUNCTION MEMBER */

void	Form::beSigned(Bureaucrat *b)
{
	if (b->getGrade() < this->getMinGradeToSign())
		this->isSigned = true;
}
void	Form::signForm(void)
{
	if (this->isSigned == true)
		std::cout << this->getName() << " form signed!" << std::endl;
}