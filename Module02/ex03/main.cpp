/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 09:46:47 by blarger           #+#    #+#             */
/*   Updated: 2024/06/10 17:18:31 by blarger          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Point.hpp"

/* -------Main function to prompt user to choose his own coordinate for the program.------- */
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

/* -------Main function to test different hedge cases of the program.------- */

/* void testBSP(Point a, Point b, Point c, Point point, bool expected) {
    bool result = bsp(a, b, c, point);
    std::cout << "Point (" << point.getX() << ", " << point.getY() << ") in Triangle ("
              << a.getX() << ", " << a.getY() << "), (" << b.getX() << ", " << b.getY() << "), ("
              << c.getX() << ", " << c.getY() << "): " << (result ? "Inside" : "Outside")
              << " - Expected: " << (expected ? "Inside" : "Outside") << std::endl;
}

int main() {
    // Edge case 1: Point inside the triangle
    testBSP(Point(0, 0), Point(2, 0), Point(1, 2), Point(1, 1), true);

    // Edge case 2: Point on the edge of the triangle
    testBSP(Point(0, 0), Point(2, 0), Point(1, 2), Point(1, 0), false);

    // Edge case 3: Point at the vertex of the triangle
    testBSP(Point(0, 0), Point(2, 0), Point(1, 2), Point(0, 0), false);

    // Edge case 4: Point outside the triangle
    testBSP(Point(0, 0), Point(2, 0), Point(1, 2), Point(3, 3), false);

    // Edge case 5: Point collinear with vertices but not inside
    testBSP(Point(0, 0), Point(2, 0), Point(1, 2), Point(2, 2), false);

    // Edge case 6: Point very close to the edge but outside
    testBSP(Point(0, 0), Point(2, 0), Point(1, 2), Point(2, 0.1), false);

    // Edge case 7: Point very close to the vertex but outside
    testBSP(Point(0, 0), Point(2, 0), Point(1, 2), Point(2.1, 0), false);

    // Edge case 8: Negative coordinates
    testBSP(Point(-2, -2), Point(-4, -2), Point(-3, -4), Point(-3, -3), true);

    return 0;
} */