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

static Base	*generateA(void)
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
}


Base * Base::generate(void)
{
	int	arr[3] = {1, 2, 3};
	int	randomizedInt;

	randomizedInt = arr[rand() % 3];

	switch(randomizedInt)
	{
		case 1:
//			return (generateA());
			return (new A());
		case 2:
//			return (generateB());
			return (new B());

		case 3:
//			return (generateC());
			return (new C());
	}
	return (NULL);
}

void Base::identify(Base* p)
{
	std::cout << 
	(void)p;
}

void Base::identify(Base& p)
{
	(void)p;
}

