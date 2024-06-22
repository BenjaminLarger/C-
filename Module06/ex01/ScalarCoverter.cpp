/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarCoverterConverter.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:19:54 by blarger           #+#    #+#             */
/*   Updated: 2024/06/21 11:47:13 by blarger          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "ScalarConverter.hpp"
#include <cmath>

void	displayChar(float floatValue)
{
    try
	{
        int 	intValue = static_cast<int>(floatValue);
        char    charValue = static_cast<char>(intValue);
		if (intValue < 32 || intValue > 126)
			throw std::out_of_range("Out of printable ASCII char range");
		std::cout << YELLOW << "The char value is: " << RESET << charValue << std::endl;

    }
	catch (const std::invalid_argument& e)
	{
        std::cerr << "Invalid argument: " << e.what() << std::endl;
    }
	catch (const std::out_of_range& e)
    {
        std::cerr << RED << "Error: " << e.what() << RESET << std::endl;
    }
}

bool    isNanOrInfiniteNumber(float number)
{
    if (number != number)
    {
        std::cout << RED << "ERROR: input is not a number" << RESET << std::endl;
        return (true);
    }
    if (std::isinf(number))
    {
        std::cout << RED << "ERROR: input is an infinite number" << RESET << std::endl;
        return (true);
    }
    return (false);
}

/* --------------FUNCTION MEMBER */

void	ScalarConverter::convertStringToScalar(std::string str)
{
    double floatValue = atof(str.c_str());

    if (isNanOrInfiniteNumber(floatValue) == true)
    {
        return ;
    }

	std::cout << "Converting " << str << " to character, integer, flaot and double." << RESET << std::endl;

	displayChar(floatValue);

    try
	{
        std::cout << YELLOW << "The integer is: " << RESET << static_cast<int>(floatValue) << std::endl;
		std::cout << YELLOW << "The float is: " << RESET << std::setprecision(8) << static_cast<float>(floatValue) << std::endl;
        std::cout << YELLOW << "The double is: " << RESET << std::setprecision(strlen(str.c_str())) << floatValue << std::endl;
    }
	catch (const std::invalid_argument& e)
	{
        std::cerr << "Invalid argument: " << e.what() << std::endl;
    }
	catch (const std::out_of_range& e)
	{
        std::cerr << "Out of range: " << e.what() << std::endl;
    }
}