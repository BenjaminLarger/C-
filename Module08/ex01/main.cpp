/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 11:27:50 by blarger           #+#    #+#             */
/*   Updated: 2024/06/24 20:34:44 by blarger          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Span.hpp"

int main()
{
	srand(time(0));
	Span sp = Span(20);

	std::cout << YELLOW << "TEST 1--------------------------" << RESET << std::endl;
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << "Shortest span = " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span = " << sp.longestSpan() << std::endl;
	
	std::cout << YELLOW << "TEST 2--------------------------" << RESET << std::endl;
	sp.addRandomNumbers(10);
	std::cout << "Shortest span = " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span = " << sp.longestSpan() << std::endl;

	std::cout << YELLOW << "TEST 2--------------------------" << RESET << std::endl;
	sp.insertNumbers(4, 5, 42);
	std::cout << "Shortest span = " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span = " << sp.longestSpan() << std::endl;
	
	return (0);
}
