/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 16:26:32 by blarger           #+#    #+#             */
/*   Updated: 2024/05/29 20:10:20 by blarger          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Zombie.hpp"

void	Zombie::random_chump(void)
{
	Zombie	zombie;

	zombie._name = "Bizon";
	Zombie::announce();
}