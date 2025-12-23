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

/*int main()*/
/*{*/
/*	ScavTrap player1("Player1");*/
/*	ScavTrap player2("Player2");*/
/**/
/*	int round = 1;*/
/**/
/*	while (true)*/
/*	{*/
/*		std::cout << "----- Round " << round << " -----" << std::endl;*/
/**/
/*		player1.attack("Player2");*/
/*		player2.takeDamage(20);*/
/**/
/*		if (player2.getHitPoints() <= 0)*/
/*		{*/
/*			std::cout << "Player2 is dead. Player1 wins!" << std::endl;*/
/*			break;*/
/*		}*/
/**/
/*		player2.attack("Player1");*/
/*		player1.takeDamage(20);*/
/**/
/*		if (player1.getHitPoints() <= 0)*/
/*		{*/
/*			std::cout << "Player1 is dead. Player2 wins!" << std::endl;*/
/*			break;*/
/*		}*/
/**/
/*		std::cout << std::endl;*/
/*		round++;*/
/*	}*/
/**/
/*	return 0;*/
/*}*/
/**/
