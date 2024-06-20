/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:13:01 by blarger           #+#    #+#             */
/*   Updated: 2024/06/20 17:17:06 by blarger          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "AForm.hpp"

/* --------------CONSTRUCTORS */
AForm::AForm(std::string _name, int _minGradeToSign, int _minGradeToExecute) : name(_name), minGradeToSign(_minGradeToSign), minGradeToExecute(_minGradeToExecute), isSigned(false), signer("N/D")
{
	try
	{
		if (_minGradeToSign < 1 || _minGradeToExecute < 1)
			throw GradeTooLowException();
		else if (_minGradeToSign > 150 || _minGradeToExecute > 150)
			throw GradeTooHighException();
		else
			std::cout << GREEN << "AForm constructor called. Setting name to " << name << ", minimum grade to sign to " << _minGradeToSign << ", minimum grade to execute " << _minGradeToExecute << RESET << std::endl;
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

AForm::AForm() : name("Contract"), minGradeToSign(75), minGradeToExecute(10) , isSigned(false), signer("N/D")
{
	std::cout << GREEN << "AForm constructor called. Setting name to " << name << RESET << std::endl;
}

/* --------------DECONSTRUCTORS */
AForm::~AForm(void)
{
	std::cout << RED << "AForm deconstructor called!" << RESET << std::endl;
}

/* --------------OPERATORS */
std::ostream&			operator<<(std::ostream& os, const AForm& f)
{
	os << f.getName() << ", AForm minimum grade to sign " << f.getMinGradeToSign() << ", AForm minimum grade to execute " << f.getMinGradeToExecute();
	return (os);
}

AForm 		&AForm::operator=(const AForm &F)
{
	this->isSigned = F.isSigned;
	this->signer = F.signer;
	return(*this);
}

/* --------------COPY */
AForm::AForm(const AForm& other) : name(other.name), minGradeToSign(other.minGradeToSign), minGradeToExecute(other.minGradeToExecute)
{
    std::cout << GREEN << "AForm calling copy assignment!" << RESET << std::endl;
}

/* --------------GETTER */
int				AForm::getMinGradeToSign(void) const {return (this->minGradeToSign);}
int				AForm::getMinGradeToExecute(void) const {return (this->minGradeToExecute);}

bool			AForm::getIsSigned(void) const
{
	return (this->isSigned);
}

std::string		AForm::getName(void) const {return (this->name);}
std::string		AForm::getSigner(void) const {return (this->signer);};

/* --------------NON OBJECT CREATOR GETTER */
int				AForm::getFixedMinGradeToSign(void) const {return (75);}
int				AForm::getFixedMinGradeToExecute(void) const {return (30);}

/* --------------SETTER */
void					AForm::setIsSigned(void) { this->isSigned = true ;}

/* --------------FUNCTION MEMBER */

void	AForm::beSigned(Bureaucrat *b)
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

bool	AForm::checkRequirement(int minGradeToExecute, Bureaucrat const &executor) const
{
	try
	{
		if (executor.getGrade() > minGradeToExecute)
		{
			throw GradeTooLowException();
		}
		else
			return (true);
	}
	catch (std::exception& e)
	{
		std::cout << ORANGE << "An exception occurred." << e.what() << RESET << std::endl;
		return (false);
	}
	catch (...)
	{
		std::cout << RED << "An unknown exception occurred." << RESET << std::endl;
		return (false);
	}
}
