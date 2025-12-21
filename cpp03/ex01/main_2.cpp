#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main()
{
	ClapTrap clap("Clappy");
	ScavTrap scav("Scavvy");

	std::cout << std::endl;

	clap.attack("a target");
	scav.attack("an enemy");

	std::cout << std::endl;

	scav.takeDamage(30);
	clap.takeDamage(5);

	std::cout << std::endl;

	scav.beRepaired(20);
	clap.beRepaired(10);

	std::cout << std::endl;

	scav.guardGate();

	std::cout << std::endl;

	return 0;
}

