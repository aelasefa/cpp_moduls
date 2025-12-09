#include "Zombie.hpp"

Zombie::Zombie(){};

void Zombie::announce()const
{
	std::cout << this->name << " BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie()
{
    std::cout << this->name << " has been destroyed." << std::endl;
}

void Zombie::setName(std::string name)
{
	this->name = name;
}
