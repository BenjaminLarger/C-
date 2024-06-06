/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 09:32:38 by blarger           #+#    #+#             */
/*   Updated: 2024/06/06 21:11:38 by blarger          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Fixed.hpp"

int	main(void)
{
	Fixed		a;
	Fixed const	b(Fixed(5.05f) * Fixed(2));

	std::cout << GREEN << "1. " <<   a << RESET << std::endl;
	std::cout << GREEN << "2. " <<  ++a << RESET << std::endl;
	std::cout << GREEN << "3. " <<  a << RESET << std::endl;
	std::cout << GREEN << "4. " <<  a++ << RESET << std::endl;
	std::cout << GREEN << "5. " <<  a << RESET << std::endl;

	std::cout << YELLOW << "6. " <<  b << RESET << std::endl;

	std::cout << YELLOW << "7. " << Fixed::max(a, b) << RESET << std::endl;

	return (0);
}
