/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 09:46:47 by blarger           #+#    #+#             */
/*   Updated: 2024/06/22 08:17:47 by blarger          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Serializer.hpp"

// main.cpp
#include <iostream>
#include "Serializer.hpp"

int main() {
    Data originalData = {42, 3.14f, 'a'};
    Data* originalPtr = &originalData;

    uintptr_t serializedData = Serializer::serialize(originalPtr);

    Data* deserializedPtr = Serializer::deserialize(serializedData);

    std::cout << "Original pointer address: " << originalPtr << std::endl;
    std::cout << "Deserialized pointer address: " << deserializedPtr << std::endl;

    if (originalPtr == deserializedPtr)
	{
        std::cout << "Success: The deserialized pointer matches the original pointer." << std::endl;
    }
	else
	{
        std::cout << "Error: The deserialized pointer does not match the original pointer." << std::endl;
    }

    return 0;
}