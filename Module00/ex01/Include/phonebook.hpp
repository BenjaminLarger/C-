# ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

// ----------DEFINITION

/* MAIN PROMPTS */
# define SERVICE_PROMPT "Which service are you looking for ? {ADD, SEARCH, or EXIT): "
# define INDEX_PROMPT "What is your contact index ? ]0;9]: "
/* ADD A CONTACT */
# define FIRST_NAME "Provide your contact first name: "
# define LAST_NAME "Provide your contact last name: "
# define NICKNAME "Provide your contact nickname: "
# define PHONE_NUMBER "Provide your contact phone number: "
# define DARK_SECRET "Provide your contact dark secret: "
/* ERRORS */
# define BAD_INDEX "Please, provide an index between 1 and 9 included: "
# define EMPTY_OUTPUT "Please, provide a non-empty output: "


// ----------INCLUDE

#include <iostream>
#include <cstring>
#include <stdlib.h>
#include "contact.class.hpp"
#include "phonebook.class.hpp"

using namespace std;


// ----------FUNCTIONS

/* PROMPTS */
char	*prompt_user(const char *prompt);
int		prompt_an_integer(const char *prompt);

/* ADD CONTACTS */
void			add_contact(Phonebook *phonebook, Contact *contact);

/* SEARCH CONTACT */
void			search_contact(Phonebook *phonebook, Contact *contact);
void			display_contacts_info(Phonebook *phonebook);
//std::string		print_contact(std::string info)



#endif