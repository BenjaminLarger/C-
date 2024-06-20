/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 09:46:47 by blarger           #+#    #+#             */
/*   Updated: 2024/06/20 19:41:29 by blarger          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
    Bureaucrat bob("Bob", 5);
    Intern  someRandomIntern;
    AForm*   rrf;

    rrf = someRandomIntern.makeForm("president request", "Bender");

    bob.signForm(rrf);
    bob.executeForm(*rrf);


    std::cout << "------------------------" << std::endl;

    rrf = someRandomIntern.makeForm("robotomy request", "Bender");

    if (rrf)
    {
        bob.signForm(rrf);
        bob.executeForm(*rrf);
    }   

    std::cout << "------------------------" << std::endl;

    rrf = someRandomIntern.makeForm("shrubery request", "Bender");

    if (rrf)
    {
        bob.signForm(rrf);
        bob.executeForm(*rrf);
    }

    std::cout << "------------------------" << std::endl;

    rrf = someRandomIntern.makeForm("other request", "Bender");

    if (rrf)
    {
        bob.signForm(rrf);
        bob.executeForm(*rrf);
    }

    delete rrf;

    return 0;
}