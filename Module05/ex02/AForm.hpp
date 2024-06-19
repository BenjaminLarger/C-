/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:06:17 by blarger           #+#    #+#             */
/*   Updated: 2024/06/19 19:02:55 by blarger          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

// ************************************************************************** //
//                               Class                                		  //
// ************************************************************************** //

#pragma once
#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;
class Form {

private:
	const std::string		name;
	const int				minGradeToSign;
	const int				minGradeToExecute;
	bool					isSigned;
	std::string				signer;
	
public:
	Form();
	Form(std::string _name, int _minGradeToSign, int _minGradeToExecute);
	Form(const Form& other);
	virtual ~Form(void);

	Form	&operator=(const Form &other);

	virtual std::string		getName(void) const;
	bool			getIsSigned(void) const;
	int				getMinGradeToSign(void) const;
	int				getMinGradeToExecute(void) const;
	std::string		getSigner(void) const;
	
	
	class GradeTooHighException : public std::exception
	{
		const char* what() const throw()
		{
			return ("Grade too high!");
		}
	};
		
	class GradeTooLowException : public std::exception
	{
		public:
			const char* what() const throw()
			{
				return ("Grade too low!");
			}
	};

	class IsAlreadySigned : public std::exception
	{
		public:
			const char* what() const throw()
			{
				return ("Contract is already signed");
			}
	};

	void	beSigned(Bureaucrat *b);
	void	signForm(void);
};

std::ostream&			operator<<(std::ostream& os, const Form& f);

class myexception: public std::exception
{
  virtual const char* what() const throw()
  {
    return "My exception happened";
  }
} extern myex;

#endif