/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 16:27:19 by blarger           #+#    #+#             */
/*   Updated: 2024/05/31 08:23:49 by blarger          ###   ########.fr       */
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
	delete[] first_zombie;
	return (0);
}