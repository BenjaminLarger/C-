#include "phonebook.hpp"

using namespace std;

void	add_contact(Phonebook *phonebook, Contact *contact)
{
	int	index;

	index = phonebook->index;
	cout << "index = " << phonebook->index << endl;
	cout << "fn = " << phonebook->contact[index].first_name << endl;
	(void)*phonebook;
	(void)*contact;
	if (index == 8)
		index = 0;
	while (phonebook->contact[index].first_name == "")
		phonebook->contact[index].first_name = prompt_user(FIRST_NAME);
	while (phonebook->contact[index].last_name == "")
		phonebook->contact[index].last_name = prompt_user(LAST_NAME);
	while (phonebook->contact[index].nickname == "")
		phonebook->contact[index].nickname = prompt_user(NICKNAME);
	while (phonebook->contact[index].phone_number == "")
		phonebook->contact[index].phone_number = prompt_user(PHONE_NUMBER);
	while (phonebook->contact[index].darkest_secret == "")
		phonebook->contact[index].darkest_secret = prompt_user(DARK_SECRET);
	phonebook->index++;
}