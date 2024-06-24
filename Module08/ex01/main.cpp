/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 11:27:50 by blarger           #+#    #+#             */
/*   Updated: 2024/06/24 13:35:17 by blarger          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Span.hpp"

int main()
{
	srand(time(0));
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	/* std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl; */
	
	std::cout << "TEST 2--------------------------" << std::endl;
	return (0);
}
