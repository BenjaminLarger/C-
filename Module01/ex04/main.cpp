/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 09:32:38 by blarger           #+#    #+#             */
/*   Updated: 2024/06/01 19:56:09 by blarger          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "File.hpp"

int	print_error(std::string str)
{
	std::cout << RED << str << RESET << std::endl;
	return (-1);

}

int	main(int argc, char **argv)
{
	if (argc != 4)
		return (print_error(ARGC));
	return (0);
}