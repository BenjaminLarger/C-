/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 17:47:26 by blarger           #+#    #+#             */
/*   Updated: 2024/06/20 19:50:18 by blarger          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Intern.hpp"
#include <stdexcept>


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
	try
	{
		func formCreators[] = {&Intern::createShruberry, &Intern::createRobotomy, &Intern::createPresident};
		std::string formNames[] = {"shrubery request", "robotomy request", "president request"};

		for (int i = 0; i < 3; i++) {
			if (nameForm == formNames[i])
			{
				std::cout << "Intern creates " << formNames[i] << std::endl;
				return (this->*formCreators[i])(targetForm);
			}
		}
		throw InvalidNameForm();
	}
	catch(const std::exception& e)
	{
		std::cout << RED << "ERROR: " << e.what() << RESET << std::endl;
	}
	return (NULL);
	
}