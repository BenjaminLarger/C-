/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 16:27:19 by blarger           #+#    #+#             */
/*   Updated: 2024/05/30 21:18:55 by blarger          ###   ########.fr       */
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
			return (false);
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
	if (end == user_input.c_str() || errno == ERANGE || n > 2147483647)
		return (-1);
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

/* void Zombie::create_next_zombie(Zombie *zombie, Zombie *next_zombie)
{
	
}

void Zombie::get_next_zombie(Zombie *zombie)
{
} */

int main(int argc, char **argv)
{
	int N;
	Zombie *first_zombie;

	if (argc != 2)
	{
		std::cout << RED << N_PROMPT << RESET << std::endl;
		return (-1);
	}
	while ((N = prompt_user_N(MAIN, YELLOW)) < 1);
	first_zombie = zombieHorde(N, argv[1]);
	for (int i = 0; i < N; i++)
	{
		Zombie *next_zombie = first_zombie;
		delete first_zombie;
		std::cout << YELLOW << "here" << RESET << std::endl;
		*first_zombie = *next_zombie;
	}
	return (0);
}