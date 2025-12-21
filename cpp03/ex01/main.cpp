#include "ScavTrap.hpp"
#include <iostream>

int main()
{
	ScavTrap player1("Player1");
	ScavTrap player2("Player2");

	int round = 1;

	while (true)
	{
		std::cout << "----- Round " << round << " -----" << std::endl;

		player1.attack("Player2");
		player2.takeDamage(20);

		if (player2.getHitPoints() <= 0)
		{
			std::cout << "Player2 is dead. Player1 wins!" << std::endl;
			break;
		}

		player2.attack("Player1");
		player1.takeDamage(20);

		if (player1.getHitPoints() <= 0)
		{
			std::cout << "Player1 is dead. Player2 wins!" << std::endl;
			break;
		}

		std::cout << std::endl;
		round++;
	}

	return 0;
}

