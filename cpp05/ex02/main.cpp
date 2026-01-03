#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	try
	{
		Bureaucrat alice("Alice", 140);
		Bureaucrat bob("Bob", 130);       
		ShrubberyCreationForm form("home");

		std::cout << alice << std::endl;
		std::cout << bob << std::endl;
		std::cout << form << std::endl;

		alice.signForm(form);
		std::cout << form << std::endl;

		alice.executeForm(form);

		bob.executeForm(form);

		std::cout << "Check the file 'home_shrubbery' for ASCII trees." << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception caught in main: " << e.what() << std::endl;
	}

	return 0;
}

