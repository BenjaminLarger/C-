/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:06:17 by blarger           #+#    #+#             */
/*   Updated: 2024/06/22 05:53:41 by blarger          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

// ************************************************************************** //
//                               Class                                		  //
// ************************************************************************** //

#pragma once
#ifndef FORM_HPP
#define FORM_HPP

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

	virtual std::string		getName(void) const;
	bool			getIsSigned(void) const;
	int				getMinGradeToSign(void) const;
	int				getMinGradeToExecute(void) const;
	std::string		getSigner(void) const;

	void					setIsSigned(void);
	
	Form	&operator=(const Form &other);
	void	beSigned(Bureaucrat *b);
	
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