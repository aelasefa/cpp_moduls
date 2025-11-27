#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>

class Contact 
{
	private:
			std::string firstname;
			std::string lastname;
			std::string nickname;
			std::string phone_number;
			std::string darkestsecret;

	public:
		void setFirstName(const std::string&);
		void setLastName(const std::string&);
		void setNickname(const std::string&);
		void setPhoneNumber(const std::string&);
		void setDarkestSecret(const std::string&);

		std::string getFirstName() const;
		std::string getLastName() const;
		std::string getNickname() const;
		std::string getPhoneNumber() const;
		std::string getDarkestSecret() const;

		void displayfull() const;
};
#endif
