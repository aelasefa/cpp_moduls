#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap():ClapTrap(){

	_hitPoints = 100;
	_energyPoint = 50;
	_attackDamage= 20;

	if(DEBUG_MESSAGES)
		std::cout << "ScavTrap: Default constructor Colled" << std::endl;
}

ScavTrap::ScavTrap(const std::string &name):ClapTrap(name)
{

	_hitPoints = 100;
	_energyPoint = 50;
	_attackDamage = 20;

	if (DEBUG_MESSAGES)
		std::cout << "ScavTrap: Name constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other):ClapTrap(other)
{

	if (DEBUG_MESSAGES)
		std::cout << "ScavTrap: Copy constructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &obj)
{

	if (DEBUG_MESSAGES)
		std::cout << "ScavTrap: Copy assignment operator called" << std::endl;
	if (this != &obj)
	{
		ClapTrap::operator=(obj);
	}
	return *this;
}

ScavTrap::~ScavTrap()
{

	if (DEBUG_MESSAGES)
		std::cout << "ScavTrap: Destructor called" << std::endl;
}

void ScavTrap::attack(const std::string &target)
{

	if (_hitPoints <= 0)
	{
		std::cout << "ScavTrap " << _name << " is dead and cannot attack." << std::endl;
		return;
	}
	if (_energyPoint <= 0)
	{
		std::cout << "ScavTrap " << _name << " has no energy left to attack." << std::endl;
		return;
	}
	_energyPoint--;
	std::cout << "ScavTrap " << _name
			  << " attacks " << target
			  << ", causing " << _attackDamage
			  << " points of damage!" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << _name
			  << " has entered Gate Keeper mode." << std::endl;
}
