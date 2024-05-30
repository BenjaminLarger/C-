/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 16:26:32 by blarger           #+#    #+#             */
/*   Updated: 2024/05/30 16:21:38 by blarger          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Zombie.hpp"
#include <cstdlib> // for std::rand and std::srand



std::string	generate_random_name(void)
{
	int	random_index;
	std::string	names[] = {"Tommy Shelby", "Heisenberg", "Saul Goodman", "Rick", "Sully"};

	random_index = rand() % 5;
	return names[random_index];
}

void	Zombie::random_chump(std::string name)
{
	Zombie	zombie;

	zombie.name = name;
	zombie.announce();
}