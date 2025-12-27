#include "Character.hpp"
#include <iostream>

Character::Character(std::string const & name) : name(name)
{
    for (int i = 0; i < 4; ++i)
        inventory[i] = NULL;
    std::cout << "Character " << name << " constructed" << std::endl;
}

Character::Character(const Character &other) : name(other.name)
{
    for (int i = 0; i < 4; ++i) {
        if (other.inventory[i])
            inventory[i] = other.inventory[i]->clone();
        else
            inventory[i] = NULL;
    }
    std::cout << "Character copy constructor called" << std::endl;
}

Character &Character::operator=(const Character &other)
{
    if (this != &other) {
        name = other.name;

        for (int i = 0; i < 4; ++i) {
            delete inventory[i];
            inventory[i] = NULL;
        }

        for (int i = 0; i < 4; ++i) {
            if (other.inventory[i])
                inventory[i] = other.inventory[i]->clone();
            else
                inventory[i] = NULL;
        }
    }
    std::cout << "Character copy assignment operator called" << std::endl;
    return *this;
}

Character::~Character()
{
    for (int i = 0; i < 4; ++i)
        delete inventory[i];
    std::cout << "Character " << name << " destructed" << std::endl;
}

std::string const & Character::getName() const
{
    return name;
}

void Character::equip(AMateria* m)
{
    if (!m)
        return;

    for (int i = 0; i < 4; ++i) {
        if (!inventory[i]) {
            inventory[i] = m;
            std::cout << "Equipped materia in slot " << i << std::endl;
            return;
        }
    }
    std::cout << "Inventory full, cannot equip materia" << std::endl;
}

void Character::unequip(int idx)
{
    if (idx < 0 || idx >= 4)
        return;
    if (inventory[idx]) {
        inventory[idx] = NULL;
        std::cout << "Unequipped materia from slot " << idx << std::endl;
    }
}

void Character::use(int idx, ICharacter& target)
{
    if (idx < 0 || idx >= 4)
        return;
    if (inventory[idx]) {
        inventory[idx]->use(target);
    }
}
