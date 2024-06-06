/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 16:27:19 by blarger           #+#    #+#             */
/*   Updated: 2024/06/06 15:37:21 by blarger          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <iostream>

/* 
REFERNCE IN C++ -------->

In C++, a reference is a type of variable that acts as an alias for another 
object or value. It's essentially another name for an existing variable.
Once a reference is initialized to an object, it cannot be changed to refer to
another object. The reference itself isn't an object; it's just another name for
an existing object.

Here are some key points about references in C++:

A reference must be initialized when it is declared.
A reference always refers to the object with which it was initialized.
A reference cannot be null.
A reference has the same type as the object it refers to.
A reference must be of the same const-ness as the object it refers to. For example, a const reference can only refer to a const object. */

int main()
{
	std::string str = "HI THIS IS BRAIN";
	void		*stringPTR = &str;
	std::string	&stringREF = str;

	std::cout << "memory address of str variable : " << &str << std::endl;
	std::cout << "memory address held by pointer : " << stringPTR << std::endl;
	std::cout << "memory address held by reference : " << &stringREF << std::endl;
	std::cout << "value of the string variable : " << str << std::endl;
	std::cout << "value of the string pointer : " << *(static_cast<std::string*>(stringPTR)) << std::endl;
	std::cout << "value of the string reference : " << stringREF << std::endl;
}