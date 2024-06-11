/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:14:46 by blarger           #+#    #+#             */
/*   Updated: 2024/06/11 17:38:04 by blarger          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#pragma once
#ifndef ANIMAL_HPP
#define ANIMAL_HPP

// ----------INCLUDE
#include <iostream> 

// ----------COLORS
#define RESET   "\033[0m"
#define BLACK   "\033[30m"
#define RED     "\033[1;31m"
#define DARK_RED "\033[2;31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define ORANGE "\033[38;5;214m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[1; 37m"
#define GREY "\033[1;30m"

// ************************************************************************** //
//                               Class                                		  //
// ************************************************************************** //

class AAnimal {

private:
	std::string		type;
	
public:
	AAnimal();
	AAnimal(std::string _name);
	AAnimal(const AAnimal& other);
	virtual ~AAnimal(void);

	std::string		getType(void) const;

	virtual void	makeSound(void) const = 0;
};

class Brain {

private:
	std::string*	idea;
	
public:
	Brain();
	Brain(std::string _name);
	Brain(const Brain& other);
	~Brain(void);
};

class Dog : public AAnimal {

private:
	Brain* idea;

public:
	Dog();
	Dog(std::string _name);
	Dog(const Dog& other);
	~Dog(void);

	virtual void	makeSound( void ) const;
};

class Cat : public AAnimal {

private:
	Brain* idea;
public:
	Cat();
	Cat(std::string _name);
	Cat(const Cat& other);
	~Cat(void);

	virtual void	makeSound( void ) const;
};


#endif