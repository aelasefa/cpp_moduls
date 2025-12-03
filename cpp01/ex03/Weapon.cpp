#include "Weapon.hpp"
#include "HumanB.hpp"

Weapon::Weapon(std::string _type)
{
	type = _type;
}

void HumanB::setWeapon(Weapon& w)
{
	weapon = &w;
}
const std::string& Weapon::getType()const
{
	return type;
}

void Weapon::setType(std::string value)
{
	type = value;
}
