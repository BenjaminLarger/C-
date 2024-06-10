/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 09:32:38 by blarger           #+#    #+#             */
/*   Updated: 2024/06/10 17:24:12 by blarger          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Fixed.hpp"

int	main(void)
{
	Fixed		_a;
	Fixed const	_b(Fixed(5.05f) * Fixed(2));

	std::cout << _a << std::endl;
	std::cout << ++_a << std::endl;
	std::cout << _a << std::endl;
	std::cout << _a++ << std::endl;
	std::cout << _a << std::endl;

	std::cout << _b << std::endl;

	std::cout << Fixed::max(_a, _b) << std::endl;

	Fixed a;
    Fixed const b(2);
    Fixed const c(3);
    Fixed const d(b);

    a = Fixed(1);

    std::cout << YELLOW << "a is " << a << std::endl;
    std::cout << "b is " << b << std::endl;
    std::cout << "c is " << c << std::endl;
    std::cout << "d is " << d << RESET << std::endl;
    std::cout << CYAN << "a + c is " << a + c << std::endl;
    std::cout << "a - c is " << a - c << std::endl;
    std::cout << "a * c is " << a * c << std::endl;
    std::cout << "a / c is " << a / c << std::endl;
    std::cout << "a > b is " << (a > b) << std::endl;
    std::cout << "a < b is " << (a < b) << RESET << std::endl;
    std::cout << MAGENTA << "a >= b is " << (a >= b) << std::endl;
    std::cout << "a <= b is " << (a <= b) << std::endl;
    std::cout << "a == b is " << (a == b) << std::endl;
    std::cout << "a != b is " << (a != b) << RESET << std::endl;
    std::cout << ORANGE << "++a is " << ++a << std::endl;
    std::cout << "a is " << a << std::endl;
    std::cout << "a++ is " << a++ << std::endl;
    std::cout << "a is " << a << std::endl;
    std::cout << "--a is " << --a << std::endl;
    std::cout << "a is " << a << std::endl;
    std::cout << "a-- is " << a-- << RESET << std::endl;
    std::cout << "a is " << a << std::endl;
    std::cout << BLUE << "Fixed::min(a, b) is " << Fixed::min(a, b) << std::endl;
    std::cout << "Fixed::max(a, b) is " << Fixed::max(a, b) << RESET << std::endl;

	return (0);
}
