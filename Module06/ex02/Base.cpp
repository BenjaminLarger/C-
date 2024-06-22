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

Base * Base::generate(void)
{
	int	arr[3] = {1, 2, 3};
	int	randomizedInt;

	randomizedInt = rand() % 3 == 0;

	switch(randomizedInt)
	{
		case 1:
			Base	*aPtr = new A();
			A		*basePtr1 = dynamic_cast<A*>(aPtr);
			return (basePtr1);
		case 2:
			Base	*bPtr = new B();
			A		*basePtr2 = dynamic_cast<A*>(basePtr);
			return (basePtr);
		case 3:
			C	c;
			return (static_cast<Base>(c));
	}
	return (this);
}

void Base::identify(Base* p)
{;}

void Base::identify(Base& p)
{}

