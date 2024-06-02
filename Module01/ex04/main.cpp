/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 09:32:38 by blarger           #+#    #+#             */
/*   Updated: 2024/06/02 20:27:21 by blarger          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "File.hpp"

int	print_error(const char *str)
{
	std::cout << RED << str << RESET << std::endl;
	return (-1);
}



int	main(int argc, char **argv)
{
	std::string		line;
	std::string		fileContent;
	std::ofstream	outfile_fd;
	std::ifstream	infile_fd;

	if (argc != 4)
		return (print_error(ARGC));

	openInfile(argv[1], infile_fd);
	createNewFile(argv[1], infile_fd, outfile_fd);
	fileContent = readInfile(infile_fd, line);
	if (strlen(argv[2]) > 0 && strcmp(argv[3], argv[2]))
		fileContent = sedNewLine(fileContent, argv[2], argv[3]);
	outfile_fd << fileContent;
	infile_fd.close();
	outfile_fd.close();

	return (0);
}