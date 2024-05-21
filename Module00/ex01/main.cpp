#include <iostream>
#include "phonebook.class.hpp"
using namespace std;

Phonebook::Phonebook(void)
{
	cout << "Constructor called" << endl;

	this->foo = 42;
	cout << "this->foo = " << this->foo << endl;

	this->bar(); //we can call a function directly from a pointer

	return ;
}

Phonebook::~Phonebook(void)
{
	cout << "Deconstructor called" << endl;
	return ;
}

void	Phonebook::bar(void)
{
	cout << "Member function bar called" << endl;
}

int	main()
{
	Phonebook	instance;
	cout << "Instance created" << endl;

	instance.bar();
	return (0);
}