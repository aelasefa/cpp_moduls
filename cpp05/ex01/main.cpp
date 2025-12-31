#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    std::cout << "\n--- 1. Valid signing ---\n";
    try
    {
        Bureaucrat bob("Bob", 30);
        Form formA("Tax Form A", 50, 20);

        std::cout << bob << std::endl;
        std::cout << formA << std::endl;

        bob.signForm(formA);

        std::cout << formA << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n--- 2. Grade too low to sign ---\n";
    try
    {
        Bureaucrat jim("Jim", 120);
        Form formB("Secret Document", 50, 20);

        std::cout << jim << std::endl;
        std::cout << formB << std::endl;

        jim.signForm(formB);

        std::cout << formB << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n--- 3. Invalid form creation ---\n";
    try
    {
        Form wrong("Impossible Form", 0, 10);
    }
    catch (std::exception &e)
    {
        std::cout << "Exception when creating form: " << e.what() << std::endl;
    }

    return 0;
}

