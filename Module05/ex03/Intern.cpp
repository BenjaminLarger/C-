/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 17:47:26 by blarger           #+#    #+#             */
/*   Updated: 2024/06/20 19:07:22 by blarger          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Intern.hpp"


int strToInt(const char* str, int h = 0)
{
    return !str[h] ? 5381 : (strToInt(str, h+1) * 33) ^ str[h];
}

AForm* Intern::createShruberry(std::string target) {
    return new Shrubbery(target);
}

AForm* Intern::createRobotomy(std::string target) {
    return new Robotomy(target);
}

AForm* Intern::createPresident(std::string target) {
    return new President(target);
}

AForm	*Intern::makeForm(std::string nameForm, std::string targetForm)
{
	func formCreators[] = {&Intern::createShruberry, &Intern::createRobotomy, &Intern::createPresident};
    std::string formNames[] = {"shruberry request", "robotomy request", "president request"};

    for (int i = 0; i < 3; i++) {
        if (nameForm == formNames[i]) {
             return (this->*formCreators[i])(targetForm);
        }
    }

    throw std::invalid_argument("Invalid form name");
	/* Bureaucrat	bob("Bob", 5);
	int			switchCase = strToInt(nameForm.c_str());
	AForm		*form;
	const int			switchShruberry = strToInt("shruberry request");
	const int			switchRobotomy = strToInt("robotomy request");
	const int			switchPresident = strToInt("president request");

	try
	{
		switch (switchCase)
		{
			case switchShruberry:
				form = new Shrubbery(targetForm);
				return (form);
			case strToInt("robotomy request"):
				form = new Robotomy(targetForm);
				return (form);
			case strToInt("president request"):
				form = new President(targetForm);
				return (form);
			default:
				throw InvalidNameForm();
		}
		
	}
	catch (std::exception& e)
	{
		std::cout << ORANGE << "An exception occurred: " << nameForm << ". " << e.what() << RESET << std::endl;
	}
	catch (...)
	{
		std::cout << RED << "An unknown exception occurred." << RESET << std::endl;
	} */
}