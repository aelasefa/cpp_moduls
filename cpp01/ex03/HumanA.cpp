#include "HumanA.hpp"

HumanA::HumanA(const std::string &va, Weapon &wa):wp(wa)
{
	name = va; 
}

void HumanA::attack() const
{
	std::cout << name << " attacks with their " << wp.getType() << std::endl;
}

HumanA::~HumanA()
{
	std::cout << "HumanA destroyed" << std::endl;
}
