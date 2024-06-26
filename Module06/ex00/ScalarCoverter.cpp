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

ScalarConverter::ScalarConverter() {};

static void	displayChar(float floatValue)
{
    try
	{
        int 	intValue = static_cast<int>(floatValue);
        char    charValue = static_cast<char>(intValue);
		if (intValue < 32 || intValue > 126)
			throw std::out_of_range("");
		std::cout << "char: " << charValue << std::endl;

    }
	catch (const std::out_of_range& e)
    {
        std::cerr << "char: Non displayable" << e.what() << RESET << std::endl;
    }
}

static bool    isNanOrInfiniteNumber(float number)
{
    if (number != number)
    {
        std::cout << "char: impossible\nint: impossible\nflaot: nanf\ndouble nan" << std::endl;
        return (true);
    }
    if (std::isinf(number))
    {
        std::cout << RED << "ERROR: input is an infinite number" << RESET << std::endl;
        return (true);
    }
    return (false);
}

static void displayEndOfDecimal(bool isFloat, std::string str)
{
    if (!str.empty() && str[strlen(str.c_str()) - 1] == 'f') {
       str[strlen(str.c_str()) - 1] = '\0';
}    if (str == "0")
    {
        std::cout << ".0";
        if (isFloat)
            std::cout << "f";
        std::cout << std::endl;
        return;
    }

    size_t decimalPos = str.find('.');
    if (decimalPos != std::string::npos)
    {
        std::cout << str.substr(decimalPos);
        
        if (isFloat)
            std::cout << "f";
        std::cout << std::endl;
    } else {
        std::cout << ".0";
        if (isFloat)
            std::cout << "f";
        std::cout << std::endl;
    }
}

/* --------------FUNCTION MEMBER */

void	ScalarConverter::convertStringToScalar(std::string str)
{
    double floatValue = atof(str.c_str());

    if (str == "")
    {
        std::cout << RED << "ERROR: input is empty." << RESET << std::endl;
        return ;
    }

    if (isNanOrInfiniteNumber(floatValue) == true)
    {
        return ;
    }

	displayChar(floatValue);

    try
	{
        std::cout << "int: " << static_cast<int>(floatValue) << std::endl;
		std::cout << "float: " << std::setprecision(8) << static_cast<int>(floatValue);
        displayEndOfDecimal(true, str);
        std::cout << "double: " << std::setprecision(strlen(str.c_str())) << static_cast<int>(floatValue);
        displayEndOfDecimal(false, str);
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