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
			void		publicbar(void);
	
	private:
			int		_privatefoo;//convention _ avant function privee 
			void	_privateBar(void);
};

#endif