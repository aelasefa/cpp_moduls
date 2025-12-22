#include "FragTrap.hpp"
#include <iostream>

int main()
{
	FragTrap p1("Frag-One");
	FragTrap p2("Frag-Two");

	int round = 1;

	while (p1.getHitPoints() > 0 && p2.getHitPoints() > 0)
	{
		std::cout << "\n--- Round " << round << " ---" << std::endl;

		p1.attack("Frag-Two");
		p2.takeDamage(p1.getAttackDamage());

		if (p2.getHitPoints() <= 0)
			break;

		p2.attack("Frag-One");
		p1.takeDamage(p2.getAttackDamage());

		round++;
	}

	std::cout << "\n=== Fight Over ===" << std::endl;

	if (p1.getHitPoints() > 0)
		std::cout << "Frag-One wins!" << std::endl;
	else
		std::cout << "Frag-Two wins!" << std::endl;

	p1.highFivesGuys();

	return 0;
}

