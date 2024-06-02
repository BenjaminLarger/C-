/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infile.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 14:11:55 by blarger           #+#    #+#             */
/*   Updated: 2024/06/02 14:23:57 by blarger          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "File.hpp"

void	openInfile(char *infile, std::ifstream& infile_fd)
{
	infile_fd.open(infile);
	if (!infile_fd.is_open())
	{
		std::cout << RED << FILE << infile << RESET << std::endl;
		exit(EXIT_FAILURE);
	}

	return ;
}

std::string	readInfile(std::ifstream& infile_fd, std::string line)
{
	std::string		fileContent;

	while (getline(infile_fd, line))
	{
		fileContent.append(line);
		fileContent.append("\n");
	}
	return (fileContent);
}