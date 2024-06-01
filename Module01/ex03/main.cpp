/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 09:32:38 by blarger           #+#    #+#             */
/*   Updated: 2024/06/01 19:39:50 by blarger          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

int	main()
{
	{
		Weapon club = Weapon("crude spiked club");
		
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");

		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	return (0);
}