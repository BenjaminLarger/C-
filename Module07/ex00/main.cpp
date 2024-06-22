/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 09:46:47 by blarger           #+#    #+#             */
/*   Updated: 2024/06/22 19:36:29 by blarger          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Whatever.hpp"

std::ostream& operator<<(std::ostream& os, const Point& p)
{
    return os << YELLOW << "(" << p.x << ", " << p.y << ")" << RESET;
}

int main() {
    int a = 10, b = 20;
    std::cout << "Before swap: a = " << a << ", b = " << b << std::endl;
    swap(a, b);
    std::cout << "After swap: a = " << a << ", b = " << b << std::endl;

    double c = 1.1, d = 2.2;
    std::cout << "min(" << c << ", " << d << ") = " << min(c, d) << std::endl;
    std::cout << "max(" << c << ", " << d << ") = " << max(c, d) << std::endl;

    Point p1(1, 2), p2(3, 4);
    std::cout << "Before swap: p1 = " << p1 << ", p2 = " << p2 << std::endl;
    swap(p1, p2);
    std::cout << "After swap: p1 = " << p1 << ", p2 = " << p2 << std::endl;

    std::cout << "min(p1, p2) = " << min(p1, p2) << std::endl;
    std::cout << "max(p1, p2) = " << max(p1, p2) << std::endl;

    return 0;
}