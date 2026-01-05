#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern() {}

Intern::Intern(const Intern &other)
{
	(void)other;
}

Intern &Intern::operator=(const Intern &other)
{
	(void)other;
	return *this;
}

Intern::~Intern() {}

static AForm* createShrubbery(const std::string &target)
{
	return new ShrubberyCreationForm(target);
}

static AForm* createRobotomy(const std::string &target)
{
	return new RobotomyRequestForm(target);
}

static AForm* createPresidential(const std::string &target)
{
	return new PresidentialPardonForm(target);
}


AForm* Intern::makeForm(const std::string &formName, const std::string &target)
{
	std::string names[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	AForm* (*creators[3])(const std::string &target) = {
		createShrubbery,
		createRobotomy,
		createPresidential
	};

	for (int i = 0; i < 3; i++)
	{
		if (formName == names[i])
		{
			std::cout << "Intern creates " << formName << std::endl;
			return creators[i](target);
		}
	}

	std::cout << "Intern couldn't find form: " << formName << std::endl;
	return NULL;
}

