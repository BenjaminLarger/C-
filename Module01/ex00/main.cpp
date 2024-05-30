/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 16:27:19 by blarger           #+#    #+#             */
/*   Updated: 2024/05/29 20:40:47 by blarger          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Zombie.hpp"

using namespace std;

std::string		prompt_user(const char *prompt, const char *color)
{
	std::string 	user_input;

	cout << RESET << prompt << color;
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
		}
		else if (!(user_prompt.compare("RANDOM")))
			Zombie::random_chump();
		else
			cout << RED << "Invalid instruction." << RESET << endl;
		user_prompt = prompt_user(MAIN, YELLOW);
	}
	zombie->_name = "NULL";
	return (0);
}