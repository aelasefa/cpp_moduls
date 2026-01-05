#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
: AForm("ShrubberyCreationForm", target, 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
: AForm(other)
{
}

ShrubberyCreationForm &
ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	(void)other;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}


void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	checkExecution(executor);

	std::ofstream file((getTarget() + "_shrubbery").c_str());

	if (!file)
	{
		std::cerr << "Error: could not open file" << std::endl;
		return;
	}

	file <<
"        🌲🌲🌲\n"
"       🌲🌲🌲🌲\n"
"      🌲🌲🌲🌲🌲\n"
"     🌲🌲🌲🌲🌲🌲\n"
"        |||\n"
"        |||\n";
	file.close();
}

