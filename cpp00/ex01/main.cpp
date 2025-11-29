#include "phonebook.hpp"

int main() {
    Phonebook phonebook;
    std::string cmd;

    while (true) {
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";

        if (!std::getline(std::cin, cmd)) {
            std::cout << "Input ended (EOF). Exiting program.\n";
            break;
        }

        if (cmd == "ADD") {
            phonebook.addContact();
        }
        else if (cmd == "SEARCH") {
            phonebook.searchContact();
        }
        else if (cmd == "EXIT") {
            std::cout << "See you later\n";
            break;
        }
        else if (!cmd.empty()) {
            std::cout << "Unknown command. Please use: ADD, SEARCH, EXIT.\n";
        }
        else {
            std::cout << "Empty command. Try again.\n";
        }
    }
    return 0;
}
