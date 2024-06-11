/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 09:46:47 by blarger           #+#    #+#             */
/*   Updated: 2024/06/11 16:32:08 by blarger          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Animal.hpp"

int main()
{
	const int	size = 10;
	Animal** animals = new Animal*[size];

	std::cout << YELLOW << "Creating Dog objects..." << RESET << std::endl;
	for (int i = 0; i < size / 2; i++)
	{
		std::cout << YELLOW << i << ". " << RESET;
		animals[i] = new Dog();
	}
	std::cout << YELLOW << "Creating Cat objects..." << RESET << std::endl;
	for (int i = size / 2; i < size; i++)
	{
		std::cout << YELLOW << (i + size / 2) << ". " << RESET;
		animals[i] = new Cat();
	}
		
	
	for (int i = 0; i < size; i++)
	{ delete animals[i];}
	delete[] animals;

	return 0;
}