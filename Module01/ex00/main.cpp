/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 16:27:19 by blarger           #+#    #+#             */
/*   Updated: 2024/05/30 16:30:35 by blarger          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Zombie.hpp"

std::string		prompt_user(const char *prompt, const char *color)
{
	std::string 	user_input;

	std::cout << RESET << prompt << std::endl << "> " << color;
	std::getline(std::cin, user_input);
	return (user_input);
}

int	main(void)
{
	Zombie			*zombie;
	std::string		user_prompt;

	user_prompt = prompt_user(MAIN, YELLOW);
	while (user_prompt.compare("EXIT"))
	{
		if (!(user_prompt.compare("NAME")))
		{
			zombie = Zombie::name_zombie();
			zombie->announce();
			delete zombie;
		}
		else if (!(user_prompt.compare("RANDOM")))
			Zombie::random_chump(generate_random_name());
		else
			std::cout << RED << "Invalid instruction." << RESET << std::endl;
		user_prompt = prompt_user(MAIN, YELLOW);
	}
	return (0);
}