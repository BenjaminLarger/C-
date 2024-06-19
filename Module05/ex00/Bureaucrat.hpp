/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:14:46 by blarger           #+#    #+#             */
/*   Updated: 2024/06/19 18:52:51 by blarger          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#pragma once
#ifndef ANIMAL_HPP
#define ANIMAL_HPP

// ----------INCLUDE
#include <iostream>
#include <exception>

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

	std::string			getName(void) const;
	int					getGrade(void) const;

	Bureaucrat	&operator=(const Bureaucrat &other);

	void				setGrade(int newGrade);
	
	class GradeTooHighExceptions : public std::exception
	{
		const char* what() const throw()
		{
			return ("Grade too high!");
		}
	};
		
	class GradeTooLowExceptions : public std::exception
	{
		const char* what() const throw()
		{
			return ("Grade too high!");
		}
	};

	void		decrementGrade();
	void		incrementGrade();
};

std::ostream&			operator<<(std::ostream& os, const Bureaucrat& f);

class myexception: public std::exception
{
  virtual const char* what() const throw()
  {
    return "My exception happened";
  }
} extern myex;

#endif