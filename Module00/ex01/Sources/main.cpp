/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 12:29:43 by blarger           #+#    #+#             */
/*   Updated: 2024/06/02 20:44:32 by blarger          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <iostream>
#include "phonebook.hpp"

int	main()
{
	std::string		user_prompt;
	Phonebook	phonebook;

	user_prompt = prompt_user(SERVICE_PROMPT, YELLOW);
	while (user_prompt.compare("EXIT"))
	{
		if (!(user_prompt.compare("ADD")))
			add_contact(&phonebook);
		else if (!(user_prompt.compare("SEARCH")))
			search_contact(&phonebook);
		else
			std::cout << RED << "Invalid instruction." << RESET << std::endl;
		user_prompt = prompt_user(SERVICE_PROMPT, YELLOW);
	}
	return (0);
}