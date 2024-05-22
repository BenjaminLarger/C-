#include <iostream>
#include "phonebook.hpp"
using namespace std;

int	main()
{
	char		*user_prompt;
	Phonebook	phonebook;
	Contact		contact;

	user_prompt = prompt_user(SERVICE_PROMPT);
	while (strcmp(user_prompt, "EXIT"))
	{
		if (!(strcmp(user_prompt, "ADD")))
			add_contact(&phonebook, &contact);
		else if (!(strcmp(user_prompt, "SEARCH")))
			search_contact(&phonebook, &contact);
		else
			cout << "Invalid instruction." << endl;
		user_prompt = prompt_user(SERVICE_PROMPT);
	}
	return (0);
}