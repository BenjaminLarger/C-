#include <iostream>
#include "phonebook.hpp"

int	main()
{
	string		user_prompt;
	Phonebook	phonebook;

	user_prompt = prompt_user(SERVICE_PROMPT, YELLOW);
	while (user_prompt.compare("EXIT"))
	{
		if (!(user_prompt.compare("ADD")))
			add_contact(&phonebook);
		else if (!(user_prompt.compare("SEARCH")))
			search_contact(&phonebook);
		else
			cout << RED << "Invalid instruction." << RESET << endl;
		user_prompt = prompt_user(SERVICE_PROMPT, YELLOW);
	}
	return (0);
}