/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 16:27:19 by blarger           #+#    #+#             */
/*   Updated: 2024/05/30 13:29:38 by blarger          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Zombie.hpp"

std::string		prompt_user(const char *prompt, const char *color)
{
	std::string 	user_input;

	std::cout << RESET << prompt << color;
	std::getline(std::cin, user_input);
	return (user_input);
}

int	main(void)
{
	Zombie			*zombie;
	std::string		user_prompt;

	zombie = NULL;
	user_prompt = prompt_user(MAIN, YELLOW);
	while (user_prompt.compare("EXIT"))
	{
		if (!(user_prompt.compare("NAME")))
		{
			zombie = Zombie::name_zombie();
			zombie->announce();
		}
		else if (!(user_prompt.compare("RANDOM")) && zombie != NULL)
			Zombie::random_chump();
		else if (!(user_prompt.compare("ANOUNCE")))
			zombie->announce();
		else
			std::cout << RED << "Invalid instruction." << RESET << std::endl;
		user_prompt = prompt_user(MAIN, YELLOW);
	}
	zombie->_name = "NULL";
	return (0);
}