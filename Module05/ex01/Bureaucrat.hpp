/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:14:46 by blarger           #+#    #+#             */
/*   Updated: 2024/06/20 13:51:39 by blarger          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#pragma once
#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

// ----------INCLUDE
#include <iostream>
#include <exception>
#include "Form.hpp"

// ----------COLORS
#define RESET   "\033[0m"
#define BLACK   "\033[30m"
#define RED     "\033[1;31m"
#define DARK_RED "\033[2;31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define ORANGE "\033[38;5;214m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[1; 37m"
#define GREY "\033[1;30m"

// ************************************************************************** //
//                               Class                                		  //
// ************************************************************************** //

class Form;
class Bureaucrat {

private:
	const std::string		name;
	int						grade;
	
public:
	Bureaucrat();
	Bureaucrat(std::string _name);
	Bureaucrat(int _grade);
	Bureaucrat(std::string _name, int grade);
	Bureaucrat(const Bureaucrat& other);
	virtual ~Bureaucrat(void);

	virtual std::string		getName(void) const;
	int				getGrade(void) const;

	Bureaucrat	&operator=(const Bureaucrat &other);
	void			setGrade(int newGrade);
	
	class GradeTooHighException : public std::exception
	{
		const char* what() const throw()
		{
			return ("Grade too high!");
		}
	};
		
	class GradeTooLowException : public std::exception
	{
		const char* what() const throw()
		{
			return ("Grade too high!");
		}
	};

	class SomeReason : public std::exception
	{
		const char* what() const throw()
		{
			return ("some unknown reason.");
		}
	};

	void		decrementGrade(void);
	void		incrementGrade(void);
	void		signForm(Form *f);
};

	class AlreadySigned : public std::exception
	{
		const char* what() const throw()
		{
			return ("the contract is already signed.");
		}
	};

	class MinGradeTooLowToSign : public std::exception
	{
		const char* what() const throw()
		{
			return ("not enough grade to sign the contract.");
		}
	};

std::ostream&			operator<<(std::ostream& os, const Bureaucrat& f);

#endif