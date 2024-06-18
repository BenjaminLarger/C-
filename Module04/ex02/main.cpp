/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 09:46:47 by blarger           #+#    #+#             */
/*   Updated: 2024/06/18 19:02:34 by blarger          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Animal.hpp"

int main()
{
	//AAnimal	test;
	Dog			dog;
	AAnimal&	a = dog;

	a.makeSound();
	
	Dog&		b = dog;

	b.makeSound();

	return 0;
}