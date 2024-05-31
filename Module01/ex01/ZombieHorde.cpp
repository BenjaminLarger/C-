/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 19:18:55 by blarger           #+#    #+#             */
/*   Updated: 2024/05/31 08:01:54 by blarger          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Zombie.hpp"

Zombie*		zombieHorde( int N, std::string name )
{
	Zombie* horde;
	Zombie*	first_zombie;

	horde = new Zombie[N];
	for (int i = 0; i < N; i++)
	{
		(horde + i)->set_name(name);
		horde[i].announce();
	}
	first_zombie = &horde[0];
	return (first_zombie);
}