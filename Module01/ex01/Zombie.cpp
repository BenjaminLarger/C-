/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 16:26:55 by blarger           #+#    #+#             */
/*   Updated: 2024/05/31 08:31:54 by blarger          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Zombie.hpp"

static bool user_input_is_number(std::string nb)
{
	int i;

	if (nb[0] < '0' || nb[0] > '9')
		return (false);
	i = 0;
	while (nb[i])
	{
		if (nb[i] < '0' || nb[i] > '9')
		{
			std::cout << RED << BAD_INT << RESET << std::endl;
			return (false);
		}
		i++;
	}
	return (true);
}

int prompt_user_N(const char *prompt, const char *color)
{
	std::string user_input;
	char *end;
	long int n;

	std::cout << RESET << prompt << std::endl
			  << "> " << color;
	std::getline(std::cin, user_input);
	if (user_input_is_number(user_input) == false)
		return (-1);
	n = strtol(user_input.c_str(), &end, 10);
	if (end == user_input.c_str() || errno == ERANGE || n > 21474836)
	{
		std::cout << RED << BAD_INT << RESET << std::endl;
		return (-1);
	}
	else
		return ((int)n);
}

std::string prompt_user(const char *prompt, const char *color)
{
	std::string user_input;

	std::cout << RESET << prompt << std::endl
			  << "> " << color;
	std::getline(std::cin, user_input);
	return (user_input);
}

Zombie::Zombie(void)
{
	return ;
}

Zombie::~Zombie(void)
{
	return ;
}
