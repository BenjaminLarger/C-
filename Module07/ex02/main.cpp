/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 09:46:47 by blarger           #+#    #+#             */
/*   Updated: 2024/06/23 09:27:41 by blarger          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Array.hpp"

int main()
{
    Array<int> defaultArray;
    std::cout << "Default array size: " << defaultArray.size() << std::endl;
	std::cout << YELLOW<< "----------------------------------------------------" << RESET << std::endl;

    Array<int> sizedArray(5);
    std::cout << "Sized array size: " << sizedArray.size() << std::endl;
		std::cout << YELLOW<< "----------------------------------------------------" << RESET << std::endl;

    for (unsigned int i = 0; i < sizedArray.size(); ++i) {
        sizedArray[i] = i * 10;
        std::cout << "sizedArray[" << i << "] = " << sizedArray[i] << std::endl;
    }
		std::cout << YELLOW<< "----------------------------------------------------" << RESET << std::endl;

    Array<int> copiedArray(sizedArray);
    std::cout << "Copied array size: " << copiedArray.size() << std::endl;
		std::cout << YELLOW<< "----------------------------------------------------" << RESET << std::endl;

    sizedArray[0] = 100;
    std::cout << "After modification, sizedArray[0] = " << sizedArray[0] << std::endl;
    std::cout << "Copied array[0] remains unchanged: " << copiedArray[0] << std::endl;
		std::cout << YELLOW<< "----------------------------------------------------" << RESET << std::endl;

    try {
        std::cout << "Accessing out of bounds: " << sizedArray[10] << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
		std::cout << YELLOW<< "----------------------------------------------------" << RESET << std::endl;

    return 0;
}