/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 11:13:49 by blarger           #+#    #+#             */
/*   Updated: 2024/06/08 11:14:37 by blarger          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Point.hpp"

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