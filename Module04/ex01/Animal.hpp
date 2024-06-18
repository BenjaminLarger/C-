/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:14:46 by blarger           #+#    #+#             */
/*   Updated: 2024/06/18 18:45:31 by blarger          ###   ########.fr       */
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

/* The destructor in the Animal class is declared as virtual to ensure that the correct
	destructor is called when an object of a derived class is deleted through a pointer
	to the base class.

In C++, if a class has any virtual functions, it should also have a virtual destructor.
	This is because when you delete a derived class object using a pointer to a base
	class that has a non-virtual destructor, the behavior is undefined in C++.

However, if the base class's destructor is virtual, deleting a derived class object
	using a pointer to the base class will call the derived class's destructor first,
	and then the base class's destructor. This ensures that all the resources used by
	the object are correctly released, and it's especially important if the derived
	class uses resources that aren't managed by the base class. */

class Animal {

private:
	std::string		type;
	
public:
	Animal();
	Animal(std::string _name);
	Animal(const Animal& other);
	virtual ~Animal(void);

	std::string		getType(void) const;

	virtual void	makeSound(void) const;
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

class Dog : public Animal {

private:
	Brain* idea;

public:
	Dog();
	Dog(std::string _name);
	Dog(const Dog& other);
	~Dog(void);

	virtual void	makeSound( void ) const;
};

class Cat : public Animal {

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