#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	Zombie *New_Zombies = new Zombie[N];
	if (!New_Zombies)
	{
		std::cout << "Memory allocation failed" << std::endl;
		exit(1);
	}
	for(int i = 0; i < N; i++)
		New_Zombies[i].setName(name);
	return New_Zombies;
}
