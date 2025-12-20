#include "ClapTrap.hpp"
#include <iostream>

int main()
{
    ClapTrap player1("Player1");
    ClapTrap player2("Player2");

	player1.setAttackDamage(2);
	player2.setAttackDamage(1);

	int round = 1;

    while (true)
    {
        std::cout << "=== Round " << round << " ===" << std::endl;

        player1.attack("Player2");
        player2.takeDamage(player1.getAttackDamage());

        if (player2.getHitPoints() == 0)
        {
            std::cout << "Player2 is dead! Player1 wins!" << std::endl;
            break;
        }

        player2.attack("Player1");
        player1.takeDamage(player2.getAttackDamage());

        if (player1.getHitPoints() == 0)
        {
            std::cout << "Player1 is dead! Player2 wins!" << std::endl;
            break;
        }

        round++;
    }

    return 0;
}

