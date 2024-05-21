#include "phonebook.hpp"

using namespace std;

std::string		print_contact(std::string info)
{
	for(int i = 0; i < 10 - info.length)
		cout << ' ';
	i = 0;
	while (info[i] != '\0' && i < 9)
	{
		cout << info[i];
		i++;
	}
	if (info[i + 1] != '\0')
		cout '.';
	else
		cout << info[i];
	cout << endl;
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