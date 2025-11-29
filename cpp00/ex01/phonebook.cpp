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
    size_t digitsCount = phone.length() - start;

    if (digitsCount < 8) {
        std::cout << "Phone number is too short. Minimum 8 digits required.\n";
        return false;
    }
    if (digitsCount > 15) {
        std::cout << "Phone number is too long. Maximum 15 digits allowed.\n";
        return false;
    }

    for (size_t i = start; i < phone.length(); i++) {
        if (!isdigit(phone[i])) {
            std::cout << "Phone number must contain digits only (except optional leading '+').\n";
            return false;
        }
    }

    return true;
}

void Phonebook::addContact() {
    Contact c;
    std::string input;

    // ---------- FIRST NAME ----------
    while (true) {
        if (!getField("First name: ", input))
            return;
        if (input.find_first_not_of(" \t") == std::string::npos) {
            std::cout << "First name cannot contain only spaces or tabs.\n";
            continue;
        }
        break;
    }
    c.setFirstName(input);

    // ---------- LAST NAME ----------
    while (true) {
        if (!getField("Last name: ", input))
            return;
        if (input.find_first_not_of(" \t") == std::string::npos) {
            std::cout << "Last name cannot contain only spaces or tabs.\n";
            continue;
        }
        break;
    }
    c.setLastName(input);

    // ---------- NICKNAME ----------
    while (true) {
        if (!getField("Nickname: ", input))
            return;
        if (input.find_first_not_of(" \t") == std::string::npos) {
            std::cout << "Nickname cannot contain only spaces or tabs.\n";
            continue;
        }
        break;
    }
    c.setNickName(input);

    // ---------- PHONE NUMBER ----------
    while (true) {
        if (!getField("Phone number: ", input))
            return;

        if (!isValidPhoneNumber(input))
            std::cout << "Invalid phone number! Use digits or + at start.\n";
        else
            break;
    }
    c.setPhoneNumber(input);

    // ---------- DARKEST SECRET ----------
    while (true) {
        if (!getField("Darkest secret: ", input))
            return;
        if (input.find_first_not_of(" \t") == std::string::npos) {
            std::cout << "Darkest secret cannot contain only spaces or tabs.\n";
            continue;
        }
        break;
    }
    c.setDarkestSecret(input);

    // ---------- SAVE CONTACT ----------
	int index;

	if (contact_count < 8) {
		index = contact_count;
		contact_count++;
	}
	else {
		index = contact_index;
		contact_index = (contact_index + 1) % 8;
	}
	contacts[index] = c;
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

