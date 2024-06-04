/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 09:32:38 by blarger           #+#    #+#             */
/*   Updated: 2024/06/04 17:54:31 by blarger          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Fixed.hpp"

int	main(void)
{
	Fixed		a;
	Fixed const	b(10);
	Fixed const	c(42.42f);
	Fixed const d(b);

	a = Fixed(1234.4321f);

	std::cout << ORANGE << "a is " << a << RESET << std::endl;
	std::cout << CYAN << "b is " << b << RESET << std::endl;
	std::cout << ORANGE << "c is " << c << RESET << std::endl;
	std::cout << CYAN << "d is " << d << RESET << std::endl;

	std::cout << ORANGE << "a is " << a.toInt() << " as integer" << RESET << std::endl;
	std::cout << CYAN << "b is " << b.toInt() << " as integer" << RESET << std::endl;
	std::cout << ORANGE << "c is " << c.toInt() << " as integer" << RESET << std::endl;
	std::cout << CYAN << "d is " << d.toInt() << " as integer" << RESET << std::endl;
		
	return (0);
}
