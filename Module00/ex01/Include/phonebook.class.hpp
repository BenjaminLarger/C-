# ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

#include "contact.class.hpp"

class Phonebook
{
	public:
			
			Phonebook(void);
			~Phonebook(void);
			Contact			contact[9];
			unsigned int	index;
			unsigned int	nb_of_contact;
};

#endif