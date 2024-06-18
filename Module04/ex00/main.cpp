/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 09:46:47 by blarger           #+#    #+#             */
/*   Updated: 2024/06/18 18:29:26 by blarger          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Animal.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* i = new Cat();
	const Cat* i_ = new Cat();
	const Dog* j = new Dog();
	std::cout << meta->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << i_->getType() << " " << std::endl;
	std::cout << j->getType() << " " << std::endl;
	meta->makeSound();
	i->makeSound();
	i_->makeSound();
	j->makeSound();
	delete j;
	delete i;
	delete i_;
	delete meta;

	std::cout << std::endl << "------------------------------------------------------------" << std::endl << std::endl ;

	const WrongAnimal* _meta = new WrongAnimal();
	const WrongAnimal* _i = new WrongCat();
	const WrongCat* _j = new WrongCat();
	std::cout << _meta->getType() << " " << std::endl;
	std::cout << _i->getType() << " " << std::endl;
	std::cout << _j->getType() << " " << std::endl;
	_meta->makeSound();
	_i->makeSound();
	_j->makeSound();
	delete _i;
	delete _j;
	delete _meta;
	return 0;
}
