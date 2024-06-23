/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:14:46 by blarger           #+#    #+#             */
/*   Updated: 2024/06/23 09:20:27 by blarger          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#pragma once
#ifndef ARRAY_HPP
#define ARRAY_HPP

// ----------INCLUDE
#include <iostream>
#include <exception>

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

template <typename T> class Array
{
	private:
		T* 				array;
		unsigned int 	arraySize;

	public:
		Array();
		Array(unsigned int n);
		Array(const Array& other);
		~Array();
		Array			&operator=(const Array &other);
		T&				operator[](unsigned int index);

		
		unsigned int	size(void);
};

// ************************************************************************** //
//                               Template                                		  //
// ************************************************************************** //

/* CONSTRUCTOR */
template <typename T>
Array<T>::Array(unsigned int n) : arraySize(n)
{
	this->array = new T[n];
}

template <typename T>
Array<T>::Array() : array(NULL), arraySize(0)
{}

/* DECONSTRUCTOR */
template <typename T>
Array<T>::~Array()
{
	if (this->arraySize > 0)
		delete[] this->array;
}

/* COPY ASSIGNMENT */
template <typename T>
Array<T>::Array(const Array& other)
{
	if (this != &other)
	{
		this->arraySize = other.arraySize;
		this->array = new T[this->size()];
		for (unsigned int i = 0; i < this->size(); i++)
		{
			this->array[i] = other.array[i];
		}
	}
}

/* OPERATOR */
template <typename T>
Array<T>& Array<T>::operator=(const Array &other)
{
	if (this != &other)
	{
		if (this->size() > 0)
			delete[] this->array;
		this->arraySize = other.arraySize;
		this->array = new T[this->arraySize];
		for (unsigned int i = 0; i < this->arraySize; i++)
		{this->array[i] = other.array[i];}
		
	}
	return (*this);
}

template <typename T>
T& Array<T>::operator[](unsigned int index)
{
	try
	{
		if (index >= this->size())
			throw std::exception();
	}
	catch (const std::exception& e)
	{
		std::cout << RED << "ERROR: Access to unallocated memory. Undefined behaviour prevented!" << RESET << std::endl;
		
	}
	return (this->array[index]);
	
};

template <typename T>
unsigned int Array<T>::size(void)
{return (this->arraySize);}

#endif