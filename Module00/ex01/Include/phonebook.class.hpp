# ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

#include "phonebook.hpp"

class Phonebook
{
	public:
			Phonebook(void);
			~Phonebook(void);
			void	add_contact(const Contact &contact, int index);
			Contact	get_contact(int i);
			void	get_input(void);
			void	reset_contact(Phonebook *phonebook, int index);
			unsigned int	index;
			unsigned int	nb_of_contact;
	private:
			Contact			contact[8];
};

#endif