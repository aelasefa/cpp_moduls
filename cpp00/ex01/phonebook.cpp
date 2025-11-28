#include "phonebook.hpp"

std::string Phonebook::formatField(const std::string& str) const {
    if (str.length() <= 10)
        return std::string(10 - str.length(), ' ') + str;
    return str.substr(0, 9) + ".";
}

Phonebook::Phonebook() {
    contact_index = 0;
    contact_count = 0;
}

bool getField(const std::string &prompt, std::string &field){
    std::cout << prompt;
    if (!std::getline(std::cin, field)) {
        std::cout << "\nInput cancelled (EOF).\n";
        return (false);
    }
    if (field.empty()) {
        std::cout << "Field cannot be empty\n";
        return (getField(prompt, field));
    }
    return (true);
}

bool isValidPhoneNumber(const std::string &phone) {
    size_t start = 0;

    if (phone[0] == '+')
            start++;
    for (size_t i = start; i < phone.length(); i++) {
        if (!isdigit(phone[i]))
            return (false);
    }
    return (true);
}

void Phonebook::addContact() {
    Contact c;
    std::string input;

    std::cout << "First name: ";
    std::getline(std::cin, input);
    c.setFirstName(input);

    std::cout << "Last name: ";
    std::getline(std::cin, input);
    c.setLastName(input);

    std::cout << "Nickname: ";
    std::getline(std::cin, input);
    c.setNickName(input);

    std::cout << "Phone number: ";
    std::getline(std::cin, input);
    c.setPhoneNumber(input);

    std::cout << "Darkest secret: ";
    std::getline(std::cin, input);
    c.setDarkestSecret(input);

	int index;

	if (contact_count < 8)
		index = contact_count;
	else
		index = contact_index;

    contacts[index] = c;

    if (contact_count < 8)
        contact_count++;
    else
        contact_index = (contact_index + 1) % 8;

    std::cout << "Contact added!" << std::endl;
}

void Phonebook::searchContact() const {
    if (contact_count == 0) {
        std::cout << "No contacts available.\n";
        return;
    }

    std::cout << "---------------------------------------------\n";
    std::cout << "|   Index  |First Name| Last Name| Nickname |\n";
    std::cout << "---------------------------------------------\n";

    for (int i = 0; i < contact_count; i++) {
        std::cout << "|"
                  << "    " << i << "    |"
                  << formatField(contacts[i].getFirstName()) << "|"
                  << formatField(contacts[i].getLastName()) << "|"
                  << formatField(contacts[i].getNickName()) << "|\n";
    }
    std::cout << "---------------------------------------------\n";

    std::string input;
    std::cout << "Enter index: ";
    std::getline(std::cin, input);

    if (input.size() == 1 && isdigit(input[0])) {
        int index = input[0] - '0';
        if (index >= 0 && index < contact_count) {
            contacts[index].displayFull();
            return;
        }
    }

    std::cout << "Invalid index.\n";
}

