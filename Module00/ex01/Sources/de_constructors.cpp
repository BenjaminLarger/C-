/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   de_constructors.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 12:29:38 by blarger           #+#    #+#             */
/*   Updated: 2024/05/28 12:29:38 by blarger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

Phonebook::Phonebook(void)
{
	this->index = 0;
	this->nb_of_contact = 0;
	for(unsigned int i = 0; i < 9; i++)
	{
		this->contact[i].first_name = EMPTY;
		this->contact[i].last_name = EMPTY;
		this->contact[i].nickname = EMPTY;
		this->contact[i].phone_number = EMPTY;
		this->contact[i].darkest_secret = EMPTY;
	}
	return ;
}

Phonebook::~Phonebook(void)
{
	return ;
}

Contact::Contact(void)
{
	return ;
}

Contact::~Contact(void)
{
	return ;
}
