#include "phonebook.hpp"

using namespace std;

Phonebook::Phonebook(void)
{
	this->index = 0;
	for(unsigned int i = 0; i < 9; i++)
	{
		this->contact[i].first_name = "";
		this->contact[i].last_name = "";
		this->contact[i].nickname = "";
		this->contact[i].phone_number = "";
		this->contact[i].darkest_secret = "";
	}
	return ;
}

Phonebook::~Phonebook(void)
{
	return ;
}

Contact::Contact(void)
{
	return ;
}

Contact::~Contact(void)
{
	return ;
}
