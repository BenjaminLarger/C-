/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 17:47:38 by blarger           #+#    #+#             */
/*   Updated: 2024/06/20 19:05:31 by blarger          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#pragma once
#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class AForm;
class Bureaucrat;

class Intern : public virtual Shrubbery, public virtual President, public virtual Robotomy {

private:
		
public:
	AForm*	createShruberry(std::string target);
	AForm*	createRobotomy(std::string target);
	AForm*	createPresident(std::string target); 
	AForm	*makeForm(std::string nameForm, std::string targetForm);

	class InvalidNameForm : public std::exception
	{
		const char* what() const throw()
		{
			return ("The name form is unknown.");
		}
	};
};

typedef AForm* (Intern::*func) (std::string);

#endif