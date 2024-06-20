/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 09:46:47 by blarger           #+#    #+#             */
/*   Updated: 2024/06/20 17:45:43 by blarger          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    srand (time(NULL));
    try {
        Bureaucrat bob("Bob", 5);
        AForm* form1 = new Shrubbery("home");

        std::cout << bob << std::endl;
        std::cout << *form1 << std::endl;

        bob.executeForm(*form1);
        bob.signForm(form1);
        bob.signForm(form1);
        bob.executeForm(*form1);
        std::cout << *form1 << std::endl;

        std::cout << "----------------------------" << std::endl;

        std::cout << "Robot required grades: sign 72, exec 45" << std::endl;
        AForm* form2 = new Robotomy("robot");
        bob.signForm(form2);
        bob.executeForm(*form2);
        bob.executeForm(*form2);
        bob.executeForm(*form2);
        bob.executeForm(*form2);
        std::cout << *form2 << std::endl;

        std::cout << "----------------------------" << std::endl;
        std::cout << "President required grades: sign 25, exec 5" << std::endl;
        AForm* form3 = new President("criminal");
        bob.signForm(form3);
        bob.executeForm(*form3);
        std::cout << *form3 << std::endl;
        delete form1;
        delete form2;
        delete form3;
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}