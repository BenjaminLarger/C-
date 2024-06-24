/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 11:27:50 by blarger           #+#    #+#             */
/*   Updated: 2024/06/24 12:18:05 by blarger          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "easyfind.hpp"

int	main()
{
	std::cout << YELLOW << "TEST 1---------------------------------------" << RESET << std::endl;
	std::list<int> containerList;

    containerList.push_back(2);
    containerList.push_back(45);
    containerList.push_back(8);
    containerList.push_back(6);

	try {
		::easyfind(containerList, 45);
        std::cout << GREEN << "Found: " << ::easyfind(containerList, 45) << std::endl;
    } catch (const std::out_of_range& e) {
        std::cerr << RED << 45 << e.what() << RESET <<  std::endl;
    }

    // Test 2: Element does not exist
	std::cout << YELLOW << "TEST 2---------------------------------------" << RESET << std::endl;
    try {
		::easyfind(containerList, -1);
        std::cout << GREEN << "Found: " << ::easyfind(containerList, -1) << std::endl;
    } catch (const std::out_of_range& e) {
        std::cerr << RED << -1 << e.what() << RESET <<  std::endl;
    }

    // Test 3: Empty container
		std::cout << YELLOW << "TEST 3---------------------------------------" << RESET << std::endl;
    std::list<int> emptyList;
    try {
		::easyfind(emptyList, 10);
        std::cout << GREEN << "Found: " << ::easyfind(emptyList, 10) << std::endl;
    } catch (const std::out_of_range& e) {
        std::cerr << RED << 10 << e.what() << RESET <<  std::endl;
    }

    // Test 4: Container with duplicates
		std::cout << YELLOW << "TEST 4---------------------------------------" << RESET << std::endl;
    std::list<int> duplicatesList;
	duplicatesList.push_back(5);
    duplicatesList.push_back(5);
    duplicatesList.push_back(5);
    duplicatesList.push_back(5);
    try {
		::easyfind(duplicatesList, 5);
        std::cout << GREEN << "Found: " << ::easyfind(duplicatesList, 5) << std::endl;
    } catch (const std::out_of_range& e) {
        std::cerr << RED << 5 << e.what() << RESET <<  std::endl;
    }

    // Test 5: All elements the same, searching for a different value
	std::cout << YELLOW << "TEST 5---------------------------------------" << RESET << std::endl;
    try {
		::easyfind(duplicatesList, 1);
        std::cout << GREEN << "Found: " << ::easyfind(duplicatesList, 1) << std::endl;
    } catch (const std::out_of_range& e) {
        std::cerr << RED << 1 << e.what() << RESET <<  std::endl;
    }

    return 0;
}
