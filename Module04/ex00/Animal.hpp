/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:14:46 by blarger           #+#    #+#             */
/*   Updated: 2024/06/11 12:24:24 by blarger          ###   ########.fr       */
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
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define ORANGE "\033[38;5;214m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[1; 37m"

// ************************************************************************** //
//                               Class                                		  //
// ************************************************************************** //

class Animal {

private:
	std::string		type;
	
public:
	Animal();
	Animal(std::string _name);
	Animal(const Animal& other);
	virtual ~Animal(void);

	std::string		getType(void) const;
	/* void			meow(void);
	void			bark(void); */

	virtual void	makeSound(void) const;
};

class Dog : public Animal {

private:

public:
	Dog();
	Dog(std::string _name);
	Dog(const Dog& other);
	~Dog(void);

	virtual void	makeSound( void ) const;
};

class Cat : public Animal {

private:
	
public:
	Cat();
	Cat(std::string _name);
	Cat(const Cat& other);
	~Cat(void);

	virtual void	makeSound( void ) const;
};

/* FUNCTION */
//typedef void (Animal::*func) (void);

/* ---------------------------------------------- */
/* ---------------------------------------------- */
/* -------------------WRONG----------------------- */
/* ---------------------------------------------- */

class WrongAnimal {

private:
	std::string		type;
	
public:
	WrongAnimal();
	WrongAnimal(std::string _name);
	WrongAnimal(const WrongAnimal& other);
	virtual ~WrongAnimal(void);

	std::string		getType(void) const;

	void	makeSound(void) const;
};

class WrongCat : public WrongAnimal {

private:
	
public:
	WrongCat();
	WrongCat(std::string _name);
	WrongCat(const WrongCat& other);
	~WrongCat(void);

	void	makeSound( void ) const;
};

#endif