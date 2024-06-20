/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:13:01 by blarger           #+#    #+#             */
/*   Updated: 2024/06/20 13:54:20 by blarger          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Form.hpp"

/* --------------CONSTRUCTORS */
Form::Form(std::string _name, int _minGradeToSign, int _minGradeToExecute) : name(_name), minGradeToSign(_minGradeToSign), minGradeToExecute(_minGradeToExecute), isSigned(false), signer("N/D")
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

Form::Form() : name("Noname"), minGradeToSign(75), minGradeToExecute(10) , isSigned(false), signer("N/D")
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
	os << f.getName() << ", form minimum grade to sign " << f.getMinGradeToSign() << ", form minimum grade to execute " << f.getMinGradeToExecute();
	return (os);
}

Form 		&Form::operator=(const Form &F)
{
	this->isSigned = F.isSigned;
	this->signer = F.signer;
	return (*this);
}

/* --------------COPY */
Form::Form(const Form& other) : name(other.name), minGradeToSign(other.minGradeToSign), minGradeToExecute(other.minGradeToExecute)
{
    std::cout << GREEN << "Form calling copy assignment!" << RESET << std::endl;
}

/* --------------GETTER */
int				Form::getMinGradeToSign(void) const {return (this->minGradeToSign);}
int				Form::getMinGradeToExecute(void) const {return (this->minGradeToExecute);}
bool			Form::getIsSigned(void) const {return (this->isSigned);}
std::string		Form::getName(void) const {return (this->name);}
std::string		Form::getSigner(void) const {return (this->signer);};

/* --------------SETTER */
void					Form::setIsSigned(void) { this->isSigned = true ;}

/* --------------FUNCTION MEMBER */

void	Form::beSigned(Bureaucrat *b)
{
	try
	{
		if (b->getGrade() > this->getMinGradeToSign())
			throw GradeTooLowException();
		else if (this->isSigned == true)
			throw IsAlreadySigned();
		else
		{
			std::cout << CYAN << this->getName() << " form signed!" << RESET << std::endl;
			this->isSigned = true;
			this->signer = b->getName();
		}
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
