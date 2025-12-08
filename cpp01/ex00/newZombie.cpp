#include "Zombie.hpp"

Zombie* newZombie( std::string name )
{
	Zombie *Zombie_heap =  new Zombie(name);
	if (!Zombie_heap)
	{
		std::cout << "Memory allocation failed" << std::endl;
		exit(1);
	}
	return Zombie_heap;
}
