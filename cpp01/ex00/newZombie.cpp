#include "Zombie.hpp"

Zombie* newZombie( std::string name )
{
	Zombie *Zombie_ =  new Zombie(name);
	if (!Zombie_)
	{
		std::cout << "Memory allocation failed" << std::endl;
		exit(1);
	}
	return Zombie_;
}
