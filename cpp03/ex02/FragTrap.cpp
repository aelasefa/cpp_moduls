#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap() : ClapTrap()
{
	_hitPoints = 100;
	_energyPoint = 100;
	_attackDamage = 30;

	if (DEBUG_MESSAGES)
		std::cout << "FragTrap: Default constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoint = 100;
	_attackDamage = 30;

	if (DEBUG_MESSAGES)
		std::cout << "FragTrap: Name constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	if (DEBUG_MESSAGES)
		std::cout << "FragTrap: Copy constructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &obj)
{
	if (DEBUG_MESSAGES)
		std::cout << "FragTrap: Copy assignment operator called" << std::endl;

	if (this != &obj)
		ClapTrap::operator=(obj);

	return *this;
}

FragTrap::~FragTrap()
{
	if (DEBUG_MESSAGES)
		std::cout << "FragTrap: Destructor called" << std::endl;
}

void FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << _name
			  << " requests a positive high five!" << std::endl;
}

