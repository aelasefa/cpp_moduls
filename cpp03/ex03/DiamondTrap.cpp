#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"
#include  <iostream>

DiamondTrap::DiamondTrap()
	: ClapTrap("Default_clap_name"), ScavTrap(), FragTrap(), _name("Default")
{
	if (DEBUG_MESSAGES)
		std::cout << "DiamondTrap: Default constructor called" << std::endl;

	_hitPoints = FragTrap::_hitPoints;
	_energyPoint = ScavTrap::_energyPoint;
	_attackDamage = FragTrap::_attackDamage;
}

DiamondTrap::DiamondTrap(const std::string &name)
	: ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _name(name)
{
	if (DEBUG_MESSAGES)
		std::cout << "DiamondTrap: Parameterized constructor called for " << _name << std::endl;

	_hitPoints = FragTrap::_hitPoints;
	_energyPoint = ScavTrap::_energyPoint;
	_attackDamage = FragTrap::_attackDamage;
}

DiamondTrap::~DiamondTrap()
{
	if (DEBUG_MESSAGES)
		std::cout << "DiamondTrap: Destructor called" << std::endl;
}

void DiamondTrap::attack(const std::string &target)
{
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
    std::cout << "DiamondTrap name: " << _name << std::endl;
    std::cout << "ClapTrap name: " << ClapTrap::_name << std::endl;
}
