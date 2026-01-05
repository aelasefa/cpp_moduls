#include <iostream>
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    std::cout << "\n--- 1. Try to execute unsigned form ---\n";
    try
    {
        Bureaucrat low("LowGuy", 5);
        PresidentialPardonForm form("Arthur Dent");

        low.executeForm(form);
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n--- 2. Try to sign but grade too low ---\n";
    try
    {
        Bureaucrat bob("Bob", 50);
        PresidentialPardonForm form("Ford Prefect");

        bob.signForm(form);
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n--- 3. Correct signing + execution ---\n";
    try
    {
        Bureaucrat president("President", 1);
        PresidentialPardonForm form("Trillian");

        president.signForm(form);
        president.executeForm(form);
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}

