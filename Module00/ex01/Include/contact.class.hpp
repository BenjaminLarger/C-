# ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP

class Contact
{
	public:
			Contact(void);
			~Contact(void);	
			std::string		first_name;
			std::string		last_name;
			std::string		nickname;
			std::string		phone_number;
			std::string		darkest_secret;
};

#endif