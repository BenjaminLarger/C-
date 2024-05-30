# ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

// ----------INCLUDE

#include <iostream>
#include <cstring>
#include <stdlib.h>
#include "contact.class.hpp"
#include "phonebook.class.hpp"

// ----------DEFINITION

/* MAIN PROMPTS */
# define SERVICE_PROMPT "Which service are you looking for ? {ADD, SEARCH, or EXIT): "
# define INDEX_PROMPT "What is your contact index ? [1;8]: "
/* ADD A CONTACT */
# define FIRST_NAME "Provide your contact first name: "
# define LAST_NAME "Provide your contact last name: "
# define NICKNAME "Provide your contact nickname: "
# define PHONE_NUMBER "Provide your contact phone number: "
# define DARK_SECRET "Provide your contact dark secret: "
/* ERRORS */
# define BAD_INDEX "Please, provide an index between 1 and 8 included: "
# define EMPTY_OUTPUT "Please, provide a non-empty output: "
# define EMPTY ""

// ----------NAMESPACE
using namespace std;

// ----------COLORS
#define RESET   "\033[0m"
#define BLACK   "\033[30m"
#define RED     "\033[1;31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[1; 37m"

// ----------FUNCTIONS

/* PROMPTS */
std::string		prompt_user(const char *prompt, const char *color);

/* ADD CONTACTS */
void			add_contact(Phonebook *phonebook);

/* SEARCH CONTACT */
void			search_contact(Phonebook *phonebook);
void			display_contacts_info(Phonebook *phonebook);
std::string		print_contact(std::string info);



#endif