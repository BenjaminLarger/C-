#include "phonebook.hpp"

using namespace std;

std::string		print_contact(std::string info)
{
	std::string output;

	for(long unsigned int i = 0; i < 10 - info.length(); i++)
		output += ' ';
	for (long unsigned int i = 0; i < info.length() && i < 9; i++)
		output += info[i];
	if (info.length() > 10)
		output += '.';
	else
		output += info.substr(0, 10);
	std::cout << output << " | ";
	return (output);
}

char	*prompt_user(const char *prompt)
{
	std::string 	user_input;

	cout << prompt;
	std::getline(std::cin, user_input);
	if (!(strcmp((char *)user_input.c_str(), "EXIT")))
		exit(0);
	return ((char *)user_input.c_str());
}

int	prompt_an_integer(const char *prompt)//not used yet
{
	int	user_input;

	cout << prompt;
	cin >> user_input;
	return (user_input);
}