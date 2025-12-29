#include <iostream>
#include "Bureaucrat.hpp"

int main()
{
    try {
        Bureaucrat a("Alice", 75);
        std::cout << a.getName() << " has grade " << a.getGrade() << std::endl;

        a.incrementGrade();
        std::cout << "After increment: " << a.getGrade() << std::endl;

        a.decrementGrade();
        std::cout << "After decrement: " << a.getGrade() << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    try {
        Bureaucrat b("Bob", 0);
    }
    catch (std::exception &e) {
        std::cout << "Exception creating Bob: " << e.what() << std::endl;
    }

    try {
        Bureaucrat c("Charlie", 200);
    }
    catch (std::exception &e) {
        std::cout << "Exception creating Charlie: " << e.what() << std::endl;
    }

    try {
        Bureaucrat d("Dahlia", 2);
        std::cout << d.getName() << " grade: " << d.getGrade() << std::endl;

        d.incrementGrade();
        std::cout << "After increment: " << d.getGrade() << std::endl;

        d.incrementGrade();
    }
    catch (std::exception &e) {
        std::cout << "Exception with Dahlia: " << e.what() << std::endl;
    }

    return 0;
}

