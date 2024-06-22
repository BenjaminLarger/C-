/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarCoverterConverter.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:19:54 by blarger           #+#    #+#             */
/*   Updated: 2024/06/21 11:47:13 by blarger          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

A::A(void){};
A::~A(void){};

B::B(void){}
B::~B(void){};

C::C(void){};
C::~C(void){};

Base::~Base(void){};

/* static Base	*generateA(void)
{
	A	a;
	Base		*basePtr = dynamic_cast<Base*>(&a);

	return (basePtr);
}

static Base	*generateB(void)
{
	B	b;
	Base		*basePtr = dynamic_cast<Base*>(&b);

	return (basePtr);
}

static Base	*generateC(void)
{
	C	c;
	Base		*basePtr = dynamic_cast<Base*>(&c);

	return (basePtr);
} */


Base * Base::generate(void)
{
	int	arr[3] = {1, 2, 3};
	int	randomizedInt;

	randomizedInt = arr[rand() % 3];

	switch(randomizedInt)
	{
		case 1:
			return (new A());
		case 2:
			return (new B());

		case 3:
			return (new C());
	}
	return (NULL);
}

void Base::identify(Base* base)
{

	A *a = dynamic_cast<A*>(base);
	if (a)
		std::cout << "A has been instanced" << std::endl;

    B *b = dynamic_cast<B*>(base);
	if (b)
		std::cout << "B has been instanced" << std::endl;

    C *c = dynamic_cast<C*>(base);
	if (c)
		std::cout << "C has been instanced" << std::endl;
}

void Base::identify(Base& p)
{
	Base	*base = dynamic_cast<Base*>(&p);
	try
	{
        A& a = dynamic_cast<A&>(*base);
		std::cout << "A has been instanced" << std::endl;
		(void)a;
    }
    catch (std::exception& e) {}
	try
	{
        B& b = dynamic_cast<B&>(*base);
		std::cout << "B has been instanced" << std::endl;
		(void)b;
    }
    catch (std::exception& e) {}
	try
	{
        C& c = dynamic_cast<C&>(*base);
		std::cout << "C has been instanced" << std::endl;
		(void)c;
    }
    catch (std::exception& e) {}
}

