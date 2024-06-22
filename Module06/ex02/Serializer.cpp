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

#include "Serializer.hpp"

/* 
DEFINITION uinptr
In C99, uintptr is defined as "an unsigned integer type
    with the property that any valid pointer to void can be
    converted to this type, then converted back to pointer
    to void, and the result will compare equal to the
    original pointer".

STATIC_CAST
static_casting a pointer to and from void*p reserves the address.

REINTERPRET_CAST
reinterpret_cast only guarantees that if you cast a pointer
    to a different type, and then reinterpret_cast it back
    to the original type, you get the original value.
*/

Serializer::Serializer() {};

uintptr_t Serializer::serialize(Data* ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t ptr)
{
    return reinterpret_cast<Data*>(ptr);
}
