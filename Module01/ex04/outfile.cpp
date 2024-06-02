/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outfile.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 14:13:41 by blarger           #+#    #+#             */
/*   Updated: 2024/06/02 20:25:57 by blarger          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "File.hpp"

static	std::string	createReplaceFilename(char *infile)
{
	std::string	newFilename;

	newFilename.append(infile);
	newFilename.append(".replace");

	return (newFilename);
}

void	createNewFile(char *infile, std::ifstream& infile_fd, std::ofstream& outfile_fd)
{
	std::string	outfile_name;

	outfile_name = createReplaceFilename(infile);
	outfile_fd.open(outfile_name.c_str());
	if (!outfile_fd.is_open())
	{
		std::cout << RED << FILE << "outfile" << RESET << std::endl;
		infile_fd.close();
		exit(EXIT_FAILURE);
	}

	return ;
}

std::string	sedNewLine(std::string fileContent, const char *s1, const char *s2)
{
	std::string	str_s1(s1);
	std::string	str_s2(s2);
	size_t		pos;
	std::string	newContent;

	pos = 0;
	while ((pos = fileContent.find(str_s1)) != std::string::npos)
	{
		newContent += fileContent.substr(0, pos);
		newContent += str_s2;
		 fileContent = fileContent.substr(pos + str_s1.length());
	}
	newContent += fileContent;
	return (newContent);
}