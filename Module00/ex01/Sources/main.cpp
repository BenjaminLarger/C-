#include <iostream>
#include "phonebook.hpp"
using namespace std;

int	main()
{
	string		user_prompt;
	Phonebook	phonebook;
	Contact		contact;

	user_prompt = prompt_user(SERVICE_PROMPT, YELLOW);
	while (user_prompt.compare("EXIT"))
	{
		if (!(user_prompt.compare("ADD")))
			add_contact(&phonebook, &contact);
		else if (!(user_prompt.compare("SEARCH")))
			search_contact(&phonebook, &contact);
		else
			cout << RED << "Invalid instruction." << RESET << endl;
		user_prompt = prompt_user(SERVICE_PROMPT, YELLOW);
	}
	return (0);
}