/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 08:06:19 by blarger           #+#    #+#             */
/*   Updated: 2024/06/23 08:09:13 by blarger          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

// ************************************************************************** //
//                               Class                                		  //
// ************************************************************************** //

#pragma once
#ifndef ARRAY_TPP
#define ARRAY_TPP

template <typename T> class Array
{
	private:
		T* ptr;
		int size;

	public:
		Array();
		Array(unsigned int n);
		Array(T arr[], int s);
		Array(const Array& other);
		Array	&operator=(const Array &other);
		void print();
};

#endif