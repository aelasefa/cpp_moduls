#include "phonebook.hpp"

int main() {
    Phonebook phonebook;
    std::string cmd;

    while (true) {
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin, cmd);

        if (cmd == "ADD")
            phonebook.addContact();
        else if (cmd == "SEARCH")
            phonebook.searchContact();
        else if (cmd == "EXIT")
            break;
    }
}
