#include "ClapTrap.hpp" 
#include <iostream>

ClapTrap::ClapTrap()
	: _name("Ayman"), _hitPoints(10), _energyPoint(10), _attackDamage(0)
{
	if (DEBUG_MESSAGES)
		std::cout << "ClapTrap: Default constructor called for " << _name << std::endl;
}

ClapTrap::ClapTrap(const std::string &name)
	: _name(name), _hitPoints(10), _energyPoint(10), _attackDamage(0)
{
	if (DEBUG_MESSAGES)
		std::cout << "ClapTrap: Parameterized constructor called for " << _name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	if (DEBUG_MESSAGES)
		std::cout << "ClapTrap: Copy constructor called for " << other._name << std::endl;
	*this = other;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &obj)
{
	if (DEBUG_MESSAGES)
		std::cout << "ClapTrap: Copy assignment operator called for " << obj._name << std::endl;
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
		std::cout << "ClapTrap: Destructor called for " << _name << std::endl;
}

int ClapTrap::getHitPoints() const
{
    return _hitPoints;
}

int ClapTrap::getAttackDamage() const
{
    return _attackDamage;
}

int	ClapTrap::getenergyPoint() const
{
	return _energyPoint;
}

void ClapTrap::setAttackDamage(int amount)
{
    _attackDamage = amount;
}

void ClapTrap::setHitPoints(int amount)
{
    _hitPoints = amount;
}

void ClapTrap::setEnergyPoint(int amount)
{
    _energyPoint = amount;
}

void ClapTrap::attack(const std::string &target)
{
	if (_hitPoints <= 0)
	{
		std::cout << "ClapTrap " << _name << " is dead and cannot attack." << std::endl;
		return;
	}
	if (_energyPoint <= 0)
	{
		std::cout << "ClapTrap " << _name << " has no energy left to attack." << std::endl;
		return;
	}
	_energyPoint--;
	std::cout << "ClapTrap " << _name << " attacks " << target
		<< ", causing " << _attackDamage << " points of damage!"
		<< std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints == 0)
	{
		std::cout << "ClapTrap " << _name << " is already dead." << std::endl;
		return;
	}

	if (amount >= (unsigned int)_hitPoints)
		_hitPoints = 0;
	else
		_hitPoints -= amount;

	std::cout << "ClapTrap " << _name << " takes "
		<< amount << " points of damage! Current HP: " << _hitPoints << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_hitPoints <= 0)
	{
		std::cout << "ClapTrap " << _name << " is dead and cannot be repaired." << std::endl;
		return;
	}
	if (_energyPoint <= 0)
	{
		std::cout << "ClapTrap " << _name << " has no energy left to repair." << std::endl;
		return;
	}
	_energyPoint--;
	_hitPoints += amount;
	std::cout << "ClapTrap " << _name << " is repaired for "
		<< amount << " hit points! Current HP: " << _hitPoints << std::endl;
}

