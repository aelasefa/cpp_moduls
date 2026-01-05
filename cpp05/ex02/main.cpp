#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    std::cout << "\n===== TEST 1: Sign + Execute Successfully =====\n";
    {
        Bureaucrat boss("Boss", 1);

        ShrubberyCreationForm tree("garden");
        RobotomyRequestForm robo("Bender");
        PresidentialPardonForm pardon("Arthur");

        boss.signForm(tree);
        boss.executeForm(tree);

        boss.signForm(robo);
        boss.executeForm(robo);

        boss.signForm(pardon);
        boss.executeForm(pardon);
    }

    std::cout << "\n===== TEST 2: Execute without signing =====\n";
    {
        Bureaucrat worker("Worker", 1);
        ShrubberyCreationForm tree("yard");

        worker.executeForm(tree);
    }

    std::cout << "\n===== TEST 3: Grade too low to sign =====\n";
    {
        Bureaucrat newbie("Newbie", 150);
        PresidentialPardonForm pardon("Ford");

        newbie.signForm(pardon);
    }

    std::cout << "\n===== TEST 4: Grade too low to execute =====\n";
    {
        Bureaucrat signer("Signer", 30);
        Bureaucrat executor("Executor", 150);

        ShrubberyCreationForm tree("home");

        signer.signForm(tree);
        executor.executeForm(tree);
    }

    std::cout << "\n===== TEST 5: Boundary Behavior =====\n";
    {
        try {
            Bureaucrat tooHigh("God", 0);
        } catch (std::exception &e) {
            std::cout << "Creating Bureaucrat failed: " << e.what() << std::endl;
        }

        try {
            ShrubberyCreationForm bad("target");
        } catch (std::exception &e) {
            std::cout << "Creating form failed: " << e.what() << std::endl;
        }
    }

    return 0;
}

