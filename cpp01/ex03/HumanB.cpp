#include "HumanB.hpp"

HumanB::HumanB(std::string value)
{
	name = value;
}


void HumanB::attack()
{
	std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}
HumanB::~HumanB()
{
	std::cout << "HumanB destroyed" << std::endl;
}
