/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 19:18:55 by blarger           #+#    #+#             */
/*   Updated: 2024/05/30 21:13:20 by blarger          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Zombie.hpp"

Zombie*		zombieHorde( int N, std::string name )
{
	Zombie* horde;

	horde = new Zombie[N];
	for (int i = 0; i < N; i++)
	{
		if (i < N - 1)
			(horde + i)->next = (horde + i + 1);
		else
			(horde + i)->next = NULL;
		(horde + i)->set_name(name);
		horde[i].announce();
	}
	return (&horde[0]);
}