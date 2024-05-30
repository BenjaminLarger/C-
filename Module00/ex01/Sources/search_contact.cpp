/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_contact.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 12:29:48 by blarger           #+#    #+#             */
/*   Updated: 2024/05/29 13:12:40 by blarger          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "phonebook.hpp"


static unsigned int	get_search_index(string prompt)
{
	if (!(prompt.compare("1")))
		return (1);
	else if (!(prompt.compare("2")))
		return (2);
	else if (!(prompt.compare("3")))
		return (3);
	else if (!(prompt.compare("4")))
		return (4);
	else if (!(prompt.compare("5")))
		return (5);
	else if (!(prompt.compare("6")))
		return (6);
	else if (!(prompt.compare("7")))
		return (7);
	else if (!(prompt.compare("8")))
		return (8);
	else
		return (0);
}

void	display_contacts_info(Phonebook *phonebook)
{
	std::cout << RESET;
	for (unsigned int i = 0; i < 8; i++)
	{
		cout << "         " << i + 1 << YELLOW << " | " << RESET;
		if (phonebook->contact[i].first_name == EMPTY)
			std::cout << "   <empty>" << YELLOW << " | " << RESET;
		else
			print_contact(phonebook->contact[i].first_name);
		if (phonebook->contact[i].last_name == EMPTY)
			std::cout << "   <empty>" << YELLOW << " | " << RESET;
		else
			print_contact(phonebook->contact[i].last_name);
		if (phonebook->contact[i].nickname == EMPTY)
			std::cout << "   <empty>" << YELLOW << " | " << RESET;
		else
			print_contact(phonebook->contact[i].nickname);
		std::cout << std::endl;
	}
}

static bool index_is_correct(Phonebook phonebook, unsigned int index)
{
	if (index == 0)
	{
		std::cout << RED << BAD_INDEX << RESET << std::endl;
		return (false);
	}
	else if (index > phonebook.nb_of_contact)
	{
		std::cout << RED << "You only have " << phonebook.index << " contact(s)" << RESET << std::endl;
		return (false);
	}
	else
		return (true);
}

static void		display_indexed_contact_info(Phonebook phonebook, unsigned int index)
{
	std::cout << YELLOW << "------------------------------------------------" << RESET << std::endl;
	std::cout << "INDEX:          " << index << std::endl;
	std::cout << "FIRST NAME:     " << phonebook.contact[index - 1].first_name << std::endl;
	std::cout << "LAST NAME:      " << phonebook.contact[index - 1].last_name << std::endl;
	std::cout << "NICKNAME:       " << phonebook.contact[index - 1].nickname << std::endl;
	std::cout << "PHONE NUMBER:   " << phonebook.contact[index - 1].phone_number << std::endl;
	std::cout << "DARKEST SECRET: " << phonebook.contact[index - 1].darkest_secret << std::endl;
	std::cout << YELLOW << "------------------------------------------------" << RESET << std::endl;
}

void	search_contact(Phonebook *phonebook)
{
	string			user_prompt;
	unsigned int	index;

	display_contacts_info(phonebook);
	user_prompt = prompt_user(INDEX_PROMPT, YELLOW);
	index = get_search_index(user_prompt);
	if (index_is_correct(*phonebook, index) == false)
		return ;
	display_indexed_contact_info(*phonebook, index);
}