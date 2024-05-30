# ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP

#include "phonebook.hpp"
class Contact
{
	public:
			Contact(void);
			~Contact(void);
			void setFirstName(const std::string& firstName) { first_name = firstName; }
			void setLastName(const std::string& lastName) { last_name = lastName; }
			void setNickname(const std::string& nickname) { this->nickname = nickname; }
			void setPhoneNumber(const std::string& phoneNumber) { phone_number = phoneNumber; }
			void setDarkestSecret(const std::string& darkestSecret) { darkest_secret = darkestSecret; }
			std::string	get_first_name();
			std::string	get_last_name();
			std::string	get_nickname();
			std::string	get_phone_number();
			std::string	get_darkest_secret();
	private:
			std::string		first_name;
			std::string		last_name;
			std::string		nickname;
			std::string		phone_number;
			std::string		darkest_secret;

};

#endif