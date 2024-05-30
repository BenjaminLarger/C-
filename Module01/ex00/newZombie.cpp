/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 16:26:34 by blarger           #+#    #+#             */
/*   Updated: 2024/05/30 15:42:04 by blarger          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Zombie.hpp"

using namespace std;

Zombie	*Zombie::name_zombie(void)
{
	Zombie*	new_zombie = new Zombie;

	new_zombie->name = prompt_user(NAME, YELLOW);
	return (new_zombie);
}
