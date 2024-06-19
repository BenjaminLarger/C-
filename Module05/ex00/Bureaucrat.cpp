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
	try
	{
		if (grade < 1)
			throw GradeTooLowExceptions();
		else if (grade > 150)
			throw GradeTooHighExceptions();
		else
			std::cout << GREEN << "Bureaucrat constructor called. Setting type to " << grade << " and name to " << name << RESET << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << ORANGE << "An exception occurred: " << this->getGrade() << ". " << e.what() << RESET << std::endl;
	}
	catch (...)
	{
		std::cout << RED << "An unknown exception occurred." << RESET << std::endl;
	}
}

Bureaucrat::Bureaucrat(int _grade) : name("Scoot"), grade(_grade)
{
	try
	{
		if (grade < 1)
			throw GradeTooLowExceptions();
		else if (grade > 150)
			throw GradeTooHighExceptions();
		else
			std::cout << GREEN << "Bureaucrat constructor called. Setting type to " << grade << " and name to " << name << RESET << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << ORANGE << "An exception occurred: " << this->getGrade() << ". " << e.what() << RESET << std::endl;
	}
	catch (...)
	{
		std::cout << RED << "An unknown exception occurred." << RESET << std::endl;
	}
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

/* --------------OPERATORS */
std::ostream &operator<<(std::ostream &os, const Bureaucrat &f)
{
	os << f.getName() << ", bureaucrat grade " << f.getGrade();
	return (os);
}

Bureaucrat 		&Bureaucrat::operator=(const Bureaucrat &F)
{
	this->grade = F.grade;
}

/* --------------GETTER */
int				Bureaucrat::getGrade(void) const {return (this->grade);}
std::string		Bureaucrat::getName(void) const {return (this->name);}

/* --------------SETTER */
void			Bureaucrat::setGrade(int newGrade) {this->grade = newGrade;}

/* --------------FUNCTION MEMBER */
void		Bureaucrat::decrementGrade(void)
{
	int	newGrade = this->getGrade() + 1;

	std::cout << YELLOW << "decrement function try to set " << newGrade << " to " << this->name << RESET << std::endl;
	try
	{
		if (newGrade < 1)
			throw GradeTooLowExceptions();
		else if (newGrade > 150)
			throw GradeTooHighExceptions();
		else
		{
			std::cout << MAGENTA << "Decrementing " << this->getName() <<  "'s grade to " << newGrade << RESET << std::endl;
			this->setGrade(newGrade);
		}
	}
	catch (std::exception& e)
	{
		std::cout << ORANGE << "An exception occurred: " << this->getGrade() << ". " << e.what() << RESET << std::endl;
	}
	catch (...)
	{
		std::cout << RED << "An unknown exception occurred." << RESET << std::endl;
	}
}

void		Bureaucrat::incrementGrade(void)
{
	int	newGrade = this->getGrade() - 1;

	std::cout << YELLOW << "increment function try to set " << newGrade << " to " << this->name << RESET << std::endl;

	try
	{
		if (newGrade < 1)
			throw GradeTooLowExceptions();
		else if (newGrade > 150)
			throw GradeTooHighExceptions();
		else
		{
			std::cout << MAGENTA << "Incrementing " << this->getName() <<  "'s grade to " << newGrade << RESET << std::endl;
			this->setGrade(newGrade);
		}
	}
	catch (std::exception& e)
	{
		std::cout << ORANGE << "An exception occurred: " << this->getGrade() << ". " << e.what() << RESET << std::endl;
	}
	catch (...)
	{
		std::cout << RED << "An unknown exception occurred." << RESET << std::endl;
	}
}