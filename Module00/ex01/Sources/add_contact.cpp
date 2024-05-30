/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_contact.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 12:29:30 by blarger           #+#    #+#             */
/*   Updated: 2024/05/30 15:12:23 by blarger          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "phonebook.hpp"

static bool	valid_phone_number(std::string phone_number)
{
	long unsigned int	i;

	if (phone_number == EMPTY)
		return (false);
	i = 0;
	if (phone_number[i] == '+')
	{
		if (phone_number.length() != 12)
		{
			cout << RED << "Wrong length of phone number." << RESET << endl;
			return (false);
		}
		i ++;
	}
	else if (phone_number.length() != 10)
	{
		cout << RED << "Wrong length of phone number." << RESET << endl;
		return (false);
	}
	while (i < phone_number.length())
	{
		if (phone_number[i] < '0' || phone_number[i] > '9')
		{
			cout << RED << "Enter a phone number." << RESET << endl;
			return (false);
		}
		i++;
	}
	return (true);
}

static bool	valid_input(std::string str)
{
	if (str == EMPTY)
	{
		return (false);
	}
	else
		return (true);
}

void	add_contact(Phonebook *phonebook)
{
	int			index;
	std::string	input;
	Contact		new_contact;

	if (phonebook->index == 8)
		phonebook->index = 0;
	index = phonebook->index;
	while (valid_input(input = prompt_user(FIRST_NAME, YELLOW)) == false);
	new_contact.setFirstName(input);
	while (valid_input(input = prompt_user(LAST_NAME, YELLOW)) == false);
	new_contact.setLastName(input);
	while (valid_input(input = prompt_user(NICKNAME, YELLOW)) == false);
	new_contact.setNickname(input);
	while (valid_phone_number(input = prompt_user(PHONE_NUMBER, YELLOW)) == false);
	new_contact.setPhoneNumber(input);
	while (valid_input(input = prompt_user(DARK_SECRET, YELLOW)) == false);
	new_contact.setDarkestSecret(input);
	phonebook->add_contact(new_contact, index);
	if (index < 8)
	{
		phonebook->index++;
		phonebook->nb_of_contact++;
	}
}