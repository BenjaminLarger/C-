#include "phonebook.hpp"

std::string		print_contact(std::string info)
{
	std::string output;
	int			char_written;
	int			j;

	char_written = 0;
	if (info.length() < 10)
	{
		for(long unsigned int i = 0; i < 10 - info.length(); i++)
		{
			output += ' ';
			char_written++;
		}
	}
	j = 0;
	while (char_written < 9)
	{
		output += info[j];
		char_written++;
		j++;
	}
	if (info.length() > 10)
		output += '.';
	else
		output += info[j];
	std::cout << output << YELLOW << " | " << RESET;
	return (output);
}

std::string		prompt_user(const char *prompt, const char *color)
{
	std::string 	user_input;

	std::cout << RESET << prompt << color;
	std::getline(std::cin, user_input);
	if (!(strcmp((char *)user_input.c_str(), "EXIT")))
		exit(0);
	return (user_input);
}
