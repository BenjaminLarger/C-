/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 09:32:38 by blarger           #+#    #+#             */
/*   Updated: 2024/06/03 15:45:07 by blarger          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Harl.hpp"

void	display_msg(const char *msg)
{
	std::cout << ORANGE << msg << RESET << std::endl;
}

int	print_error(const char *str)
{
	std::cout << RED << "Error: " << str << RESET << std::endl;
	return (-1);
}

enum logLevel { _DEBUG, _WARNING, _INFO, _ERROR};

int	main(int argc, char **argv)
{
	Harl harlObject;

	if (argc != 2)
		return (print_error(PARAM));
	harlObject.complain(argv[1]);
	return (0);
}
