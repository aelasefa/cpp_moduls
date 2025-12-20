#include "ClapTrap.hpp" 
#include <iostream>

ClapTrap::ClapTrap():_name("Ayman"),_hitPoints(10),_energyPoint(10),_attackDamage(0)
{
	if(DEBUG_MESSAGES)
		std::cout << "Default constructor Colled" << std::endl;
}

ClapTrap::ClapTrap(const std::string &name):
	_name(name),_hitPoints(10),_energyPoint(10),_attackDamage(0)

{
	if (DEBUG_MESSAGES)
		std::cout << "Name constructor called" << std::endl;
}
ClapTrap::ClapTrap(const ClapTrap &other)
{
	if (DEBUG_MESSAGES)
		std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &obj)
{
	if (DEBUG_MESSAGES)
		std::cout << "Copy assignment operator called" << std::endl;
	if (this != &obj)
	{
		_name = obj._name;
		_hitPoints = obj._hitPoints;
		_energyPoint = obj._energyPoint;
		_attackDamage = obj._attackDamage;
	}
	return *this;
}
ClapTrap::~ClapTrap()
{
	if (DEBUG_MESSAGES)
		std::cout << "Destructor called" << std::endl;
}
