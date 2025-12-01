#include "Zombie.hpp"

int main()
{
	std::cout << "i'm creat new Zombie in Stack" << std::endl;
	randomChump("Romiya");
	std::cout << "i'm creat new Zombie in Heap" << std::endl;
	Zombie *hash = newZombie( "lbldiya");
	hash->announce();
	delete(hash);
}
