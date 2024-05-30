/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:12:11 by blarger           #+#    #+#             */
/*   Updated: 2024/05/30 15:19:41 by blarger          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "phonebook.hpp"

void	Phonebook::add_contact(const Contact &new_contact, int index)
{
	contact[index] = new_contact;
}

Contact	Phonebook::get_contact(int i)
{
	return (contact[i]);
}

/* CONSTRUCTOR */
Phonebook::Phonebook(void)
{
	this->index = 0;
	this->nb_of_contact = 0;
	return ;
}

/* DECONSTRUCTOR */
Phonebook::~Phonebook(void)
{
	return ;
}