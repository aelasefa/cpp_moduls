#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
	Intern someRandomIntern;
	Bureaucrat boss("Boss", 1);  
	Bureaucrat employee("Employee", 150);

	AForm* form1 = NULL;
	AForm* form2 = NULL;
	AForm* form3 = NULL;
	AForm* formInvalid = NULL;

	try
	{
		form1 = someRandomIntern.makeForm("shrubbery creation", "Home");
		form2 = someRandomIntern.makeForm("robotomy request", "Bender");
		form3 = someRandomIntern.makeForm("presidential pardon", "Marvin");
		formInvalid = someRandomIntern.makeForm("unknown form", "Target");    }
	catch (std::exception &e)
	{
		std::cout << "Exception during form creation: " << e.what() << std::endl;
	}

	if (form1)
	{
		boss.signForm(*form1);
		boss.executeForm(*form1);
	}

	if (form2)
	{
		employee.signForm(*form2);
		boss.signForm(*form2);
		boss.executeForm(*form2);
	}

	if (form3)
	{
		boss.signForm(*form3);
		boss.executeForm(*form3);
	}

	delete form1;
	delete form2;
	delete form3;
	delete formInvalid;

	return 0;
}

