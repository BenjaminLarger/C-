#include "phonebook.hpp"

using namespace std;

static unsigned int	get_search_index(const char *prompt)
{
	if (!(strcmp(prompt, "1")))
		return (1);
	else if (!(strcmp(prompt, "2")))
		return (2);
	else if (!(strcmp(prompt, "3")))
		return (3);
	else if (!(strcmp(prompt, "4")))
		return (4);
	else if (!(strcmp(prompt, "5")))
		return (5);
	else if (!(strcmp(prompt, "6")))
		return (6);
	else if (!(strcmp(prompt, "7")))
		return (7);
	else if (!(strcmp(prompt, "8")))
		return (8);
	else if (!(strcmp(prompt, "9")))
		return (9);
	else if (!(strcmp(prompt, "EXIT")))
		exit(0);
	else
		return (0);
}

void	display_contacts_info(Phonebook *phonebook)
{
	for (unsigned int i = 0; i < 9; i++)
	{
		cout << "         " << i + 1 << " | ";
		if (phonebook->contact[i].first_name == "")
			cout << "   <empty>" << " | ";
		else
			print_contact(phonebook->contact[i].first_name);
		if (phonebook->contact[i].last_name == "")
			cout << "   <empty>" << " | ";
		else
			print_contact(phonebook->contact[i].last_name);
		if (phonebook->contact[i].nickname == "")
			cout << "   <empty>" << " | ";
		else
			print_contact(phonebook->contact[i].nickname);
		cout << endl;
	}
}

static bool index_is_correct(Phonebook phonebook, unsigned int index)
{
	if (index == 0)
	{
		cout << BAD_INDEX << endl;
		return (false);
	}
	else if (index > phonebook.index)
	{
		cout << "You only have " << phonebook.index << " contact(s)" << endl;
		return (false);
	}
	else
		return (true);
}

static void		display_indexed_contact_info(Phonebook phonebook, unsigned int index)
{
	cout << index << endl;
	cout << phonebook.contact[index - 1].first_name << endl;
	cout << phonebook.contact[index - 1].last_name << endl;
	cout << phonebook.contact[index - 1].nickname << endl;
	cout << phonebook.contact[index - 1].phone_number << endl;
	cout << phonebook.contact[index - 1].darkest_secret << endl;
}

void	search_contact(Phonebook *phonebook, Contact *contact)
{
	char			user_prompt[6];
	unsigned int	index;

	(void)*phonebook;
	(void)*contact;
	display_contacts_info(phonebook);
	strcpy(user_prompt, prompt_user(INDEX_PROMPT));
	index = get_search_index(user_prompt);
	while (index_is_correct(*phonebook, index) == false)
	{
		strcpy(user_prompt, prompt_user(INDEX_PROMPT));
		index = get_search_index(user_prompt);
	}
	display_indexed_contact_info(*phonebook, index);
	//(void)user_prompt;
}