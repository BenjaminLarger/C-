/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 16:26:55 by blarger           #+#    #+#             */
/*   Updated: 2024/05/29 20:35:31 by blarger          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Zombie.hpp"

Zombie::Zombie(void)
{
	std::cout << "Zombie born." << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << "Zombie " << this->_name << "destroyed." << std::endl;
}
