/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 16:27:19 by blarger           #+#    #+#             */
/*   Updated: 2024/06/03 16:25:49 by blarger          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Zombie.hpp"

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
	std::cout << GREEN << "Ptr to the first zombie : " << first_zombie << RESET << std::endl;
	std::cout << GREEN << "Name of the first zombie : " << first_zombie->get_name() << RESET << std::endl;
	delete[] first_zombie;
	return (0);
}