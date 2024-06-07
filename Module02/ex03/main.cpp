/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 09:46:47 by blarger           #+#    #+#             */
/*   Updated: 2024/06/07 14:32:45 by blarger          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Point.hpp"

std::string		prompt_user(const char *prompt, const char *color, char P)
{
	std::string 	user_input;

	std::cout << RESET << prompt << std::endl << "> " << P << color;
	std::getline(std::cin, user_input);
	return (user_input);
}

Point prompt_triangle_coordinates(std::string pointName, std::string color) {
    float x, y;

    std::cout << RESET <<  "Enter the x coordinate for point " << pointName << ": " << color;
    while(!(std::cin >> x)) 
	{
		if (std::cin.eof())
		{
			std::cout << std::endl << RED << "ctr-d was pressed" << RESET << std::endl;
			exit(0);
		}
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << RED << "Invalid input. Please enter a number: " << YELLOW;
    }
    std::cout << RESET << "Enter the y coordinate for point " << pointName << ": " << color;
    while(!(std::cin >> y))
	{
		if (std::cin.eof())
		{
			std::cout << std::endl << RED << "ctr-d was pressed" << RESET << std::endl;
			exit(0);
		}
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << RED << "Invalid input. Please enter a number: " << YELLOW;
    }
	std::cout << GREEN << "Point " << pointName << " = [" << x << ", " << y << "]" << std::endl;
	std::cout << RESET;
	if (x > 100000000 || y > 100000000 || x < -100000000 || y < -100000000)
	{
		std::cout << RED << "Invalid input" << RESET << std::endl;
		exit(0);
	}
    return Point(x, y);
}

int	main()
{
	std::string	user_prompt;

	Point	p1 = prompt_triangle_coordinates("A", YELLOW);
	Point	p2 = prompt_triangle_coordinates("B", YELLOW);
	Point	p3 = prompt_triangle_coordinates("C", YELLOW);

	Point	P = prompt_triangle_coordinates("you want to test", YELLOW);

	if (bsp(p1, p2, p3, P) == true)
	{
		std::cout << GREEN << "Point belongs to the triangle" << RESET << std::endl;
		return (1);
	}
	else
	{
		std::cout << RED << "Point does not belong to the triangle" << RESET << std::endl;
		return (-1);
	}
}

