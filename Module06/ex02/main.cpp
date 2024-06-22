/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 09:46:47 by blarger           #+#    #+#             */
/*   Updated: 2024/06/22 12:39:23 by blarger          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

// main.cpp
#include <iostream>

int main()
{
	srand(time(NULL));

    Base *ptr = Base::generate();
	Base::identify(ptr);

	Base	&ref = *ptr; 
	Base::identify(ref);
	
    return 0;
}