#include "Zombie.hpp"

void Zombie::announce()
{
	std::cout << "BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie()
{
    std::cout << this->name << " has been destroyed." << std::endl;
}
