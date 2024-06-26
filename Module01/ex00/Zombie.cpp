/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 16:26:55 by blarger           #+#    #+#             */
/*   Updated: 2024/06/03 16:18:09 by blarger          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Zombie.hpp"

Zombie::Zombie(std::string _name) : name(_name)
{
	return ;
}

Zombie::~Zombie(void)
{
	std::cout << RED << this->name << " died" << RESET << std::endl;
	return ;
}
