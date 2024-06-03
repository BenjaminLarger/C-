/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 16:26:34 by blarger           #+#    #+#             */
/*   Updated: 2024/06/02 20:45:08 by blarger          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Zombie.hpp"

Zombie	*Zombie::name_zombie(void)
{
	Zombie*	new_zombie = new Zombie;

	new_zombie->name = prompt_user(NAME, YELLOW);
	return (new_zombie);
}
