/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 09:46:47 by blarger           #+#    #+#             */
/*   Updated: 2024/06/11 10:32:31 by blarger          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Animal.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Dog* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	delete j;
	delete i;
	delete meta;

	const WrongAnimal* _meta = new WrongAnimal();
	const WrongAnimal* _i = new WrongCat();
	std::cout << YELLOW << _i->getType() << " " << std::endl;
	_i->makeSound();
	_meta->makeSound();
	std::cout << RESET;
	delete _i;
	delete _meta;
	return 0;
}