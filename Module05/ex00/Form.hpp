/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:06:17 by blarger           #+#    #+#             */
/*   Updated: 2024/06/19 12:52:00 by blarger          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

// ************************************************************************** //
//                               Class                                		  //
// ************************************************************************** //

#include "Bureaucrat.hpp"

class Form {

private:
	const std::string		name;
	bool					isSigned;
	const int				minGradeToSign;
	const int				minGradeToExecute;
	
public:
	Form();
	Form(std::string _name, int _minGradeToSign, int _minGradeToExecute);
	Form(const Form& other);
	virtual ~Form(void);

	std::string		getName(void) const;
	bool			getIsSigned(void) const;
	int				getMinGradeToSign(void) const;
	int				getMinGradeToExecute(void) const;
	
	
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