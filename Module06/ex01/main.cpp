/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 09:46:47 by blarger           #+#    #+#             */
/*   Updated: 2024/06/21 13:52:51 by blarger          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "ScalarConverter.hpp"

int main ()
{
  std::cout << BLUE << "-----------------------" << RESET << std::endl;
  ScalarConverter::convertStringToScalar("65.08555665464");
  std::cout << BLUE << "-----------------------" << RESET << std::endl;
  ScalarConverter::convertStringToScalar("5.12345678987");
  std::cout << BLUE << "-----------------------" << RESET << std::endl;
  ScalarConverter::convertStringToScalar("0");
  std::cout << BLUE << "-----------------------" << RESET << std::endl;
  ScalarConverter::convertStringToScalar("-42");
  std::cout << BLUE << "-----------------------" << RESET << std::endl;
  ScalarConverter::convertStringToScalar("2147483647");
  std::cout << BLUE << "-----------------------" << RESET << std::endl;
  ScalarConverter::convertStringToScalar("-2147483648");
  std::cout << BLUE << "-----------------------" << RESET << std::endl;
  ScalarConverter::convertStringToScalar("1e309");
  std::cout << BLUE << "-----------------------" << RESET << std::endl;
  ScalarConverter::convertStringToScalar("not_a_number");
  std::cout << BLUE << "-----------------------" << RESET << std::endl;
}