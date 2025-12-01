#include "Zombie.hpp"

Zombie* newZombie( std::string name )
{
	Zombie *Zombie_ =  new Zombie(name);
	return Zombie_;
}
