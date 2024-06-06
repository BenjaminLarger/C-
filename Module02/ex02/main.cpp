/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 09:32:38 by blarger           #+#    #+#             */
/*   Updated: 2024/06/06 11:11:37 by blarger          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Fixed.hpp"

int	main(void)
{
	Fixed		a;
	Fixed const	b(Fixed(5.05f) * Fixed(2));

	std::cout << GREEN <<  a << RESET << std::endl;
	std::cout << GREEN <<  ++a << RESET << std::endl;
	std::cout << GREEN <<  a << RESET << std::endl;
	std::cout << GREEN <<  a++ << RESET << std::endl;
	std::cout << GREEN <<  a << RESET << std::endl;

	std::cout << YELLOW <<  b << RESET << std::endl;

	std::cout << Fixed::max(a, b) << std::endl;

	return (0);
}
