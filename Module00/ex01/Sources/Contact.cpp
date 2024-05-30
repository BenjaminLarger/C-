/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:13:02 by blarger           #+#    #+#             */
/*   Updated: 2024/05/30 15:21:07 by blarger          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "phonebook.hpp"

std::string	Contact::get_first_name(void)
{
	return (first_name);
}

std::string	Contact::get_last_name(void)
{
	return (last_name);
}
std::string	Contact::get_nickname(void)
{
	return (last_name);
}
std::string	Contact::get_phone_number(void)
{
	return (phone_number);
}
std::string	Contact::get_darkest_secret(void)
{
	return (darkest_secret);
}

/* CONSTRUCTOR */
Contact::Contact(void)
{
	setFirstName(EMPTY);
	setLastName(EMPTY);
	setNickname(EMPTY);
	setPhoneNumber(EMPTY);
	setDarkestSecret(EMPTY);
	return ;
}

/* DECONSTRUCTOR */
Contact::~Contact(void)
{
	return ;
}