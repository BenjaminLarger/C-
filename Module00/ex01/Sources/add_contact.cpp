#include "phonebook.hpp"

using namespace std;

static void	reset_contact(Phonebook *phonebook, int index)
{
	phonebook->contact[index].first_name = EMPTY;
	phonebook->contact[index].last_name = EMPTY;
	phonebook->contact[index].nickname = EMPTY;
	phonebook->contact[index].phone_number = EMPTY;
	phonebook->contact[index].darkest_secret = EMPTY;
}

static bool	valid_phone_number(string phone_number)
{
	long unsigned int	i;

	if (phone_number == EMPTY)
		return (false);
	i = 0;
	if (phone_number[i] == '+')
	{
		if (phone_number.length() != 12)
		{
			cout << RED << "Wrong length of phone number." << RESET << endl;
			return (false);
		}
		i ++;
	}
	else if (phone_number.length() != 10)
	{
		cout << RED << "Wrong length of phone number." << RESET << endl;
		return (false);
	}
	while (i < phone_number.length())
	{
		if (phone_number[i] < '0' || phone_number[i] > '9')
		{
			cout << RED << "Enter a phone number." << RESET << endl;
			return (false);
		}
		i++;
	}
	return (true);
}

static bool	valid_input(string str)
{
	if (str == EMPTY)
	{
		return (false);
	}
	else
		return (true);
}

void	add_contact(Phonebook *phonebook, Contact *contact)
{
	int	index;

	if (phonebook->index == 9)
		phonebook->index = 0;
	index = phonebook->index;
	reset_contact(phonebook, index);
	(void)*phonebook;
	(void)*contact;
	while (valid_input(phonebook->contact[index].first_name) == false)
		phonebook->contact[index].first_name = prompt_user(FIRST_NAME, YELLOW);
	while (valid_input(phonebook->contact[index].last_name) == false)
		phonebook->contact[index].last_name = prompt_user(LAST_NAME, YELLOW);
	while (valid_input(phonebook->contact[index].nickname) == false)
		phonebook->contact[index].nickname = prompt_user(NICKNAME, YELLOW);
	while (valid_phone_number(phonebook->contact[index].phone_number) == false)
		phonebook->contact[index].phone_number = prompt_user(PHONE_NUMBER, YELLOW);
	while (valid_input(phonebook->contact[index].darkest_secret)  == false)
		phonebook->contact[index].darkest_secret = prompt_user(DARK_SECRET, YELLOW);
	phonebook->index++;
	if (phonebook->nb_of_contact < 9)
		phonebook->nb_of_contact++;
}