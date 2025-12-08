#include "HumanB.hpp"

HumanB::HumanB(std::string value)
{
	name = value;
	weapon = NULL;
}


void HumanB::attack()
{
	if (!weapon)
    {
        std::cout << name << " has no weapon" << std::endl;
        return;
    }
	std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}
