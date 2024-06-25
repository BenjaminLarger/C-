/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:49:49 by blarger           #+#    #+#             */
/*   Updated: 2024/06/25 18:09:27 by blarger          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "BitcoinExchange.hpp"

bool	validExtension(char *filename)
{
	int	i = 0;

	while (filename[i])
		i++;
	if (i < 5)
		return (false);
	i--;
	if (filename[i--] != 'v' || filename[i--] != 's' || filename[i--] != 'c' || filename[i] != '.')
		return (false);
	return (true);
}

int main(int argc, char **argv)
{
	std::fstream	fin;
	if (argc != 2 || validExtension(argv[1]) == false)
		std::cout << RED << BAD_INPUT << RESET << std::endl;
	
	
}