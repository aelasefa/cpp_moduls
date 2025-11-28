#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "contact.hpp"
#include <string>

class Phonebook {
	private :
		Contact contacts[8];	
		int contact_count;
		int	contact_index;
	public:
		Phonebook();
		void addContact();
		void searchContact() const;

		std::string formatField(const std::string& str) const;
};

#endif
