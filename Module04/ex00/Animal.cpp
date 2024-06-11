/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:19:54 by blarger           #+#    #+#             */
/*   Updated: 2024/06/11 10:09:29 by blarger          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Animal.hpp"

/* --------------CONSTRUCTORS */
Animal::Animal(std::string _type) : type(_type)
{
	std::cout << GREEN << "Animal constructor called. Setting type to " << _type << RESET << std::endl;
//	this->type = _type;
}

Animal::Animal() : type("N/A")
{
	std::cout << GREEN << "Animal constructor called. Setting type to " << this->type << RESET << std::endl;
//	this->type = "N/A";
}

/* --------------DECONSTRUCTORS */
Animal::~Animal(void)
{
	std::cout << RED << "Animal deconstructor called!" << RESET << std::endl;
}

/* --------------COPY */
Animal::Animal(const Animal& other) : type(other.type)
{
    std::cout << GREEN << "Animal calling copy assignment!" << RESET << std::endl;
}

/* void	Animal::meow(void) {std::cout << "Meow!" << std::endl;}
void	Animal::bark(void) {std::cout << "WARF!" << std::endl;}
 */
/* void Animal::makeSound( void ) const
{
	int	i = 0;

	func		levelMap[] = { &Animal::meow, &Animal::bark};
	std::string	levels[] = {"Cat", "Dog"};
	while (i < 2 && levels[i].compare(this->type))
		i++;

    switch(i)
	{
		case 0:
			(this->*levelMap[0])();
			break ;

		case 1:
			(this->*levelMap[1])();
			break ;

		default:
			std::cout << ORANGE << "makeSound: Animal not found !" << RESET << std::endl;;
			break ;
	}
} */

void Animal::makeSound( void ) const {std::cout << "<animal sound>" << std::endl;}


/* GETTER */
std::string		Animal::getType(void) const {return (this->type);}
