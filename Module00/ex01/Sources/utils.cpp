/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 12:29:53 by blarger           #+#    #+#             */
/*   Updated: 2024/05/29 13:13:00 by blarger          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "phonebook.hpp"

using namespace std;

std::string		print_contact(std::string info)
{
	std::string output;
	int			char_written;
	int			j;

	char_written = 0;
	if (info.length() < 10)
	{
		for(long unsigned int i = 0; i < 10 - info.length(); i++)
		{
			output += ' ';
			char_written++;
		}
	}
	j = 0;
	while (char_written < 9)
	{
		output += info[j];
		char_written++;
		j++;
	}
	if (info.length() > 10)
		output += '.';
	else
		output += info[j];
	std::cout << output << YELLOW << " | " << RESET;
	return (output);
}

std::string		prompt_user(const char *prompt, const char *color)
{
	std::string 	user_input;

	cout << RESET << prompt << color;
	std::getline(std::cin, user_input);
	return (user_input);
}
