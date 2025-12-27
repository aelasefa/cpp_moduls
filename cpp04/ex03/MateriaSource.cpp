#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource()
{
    for (int i = 0; i < 4; ++i)
        inventory[i] = NULL;
    std::cout << "MateriaSource: Default constructor called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
    for (int i = 0; i < 4; ++i) {
        if (other.inventory[i])
            inventory[i] = other.inventory[i]->clone();
        else
            inventory[i] = NULL;
    }
    std::cout << "MateriaSource: Copy constructor called" << std::endl;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
    if (this != &other) {
        for (int i = 0; i < 4; ++i) {
            delete inventory[i];
            if (other.inventory[i])
                inventory[i] = other.inventory[i]->clone();
            else
                inventory[i] = NULL;
        }
    }
    std::cout << "MateriaSource: Copy assignment operator called" << std::endl;
    return *this;
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; ++i)
        delete inventory[i];
    std::cout << "MateriaSource: Destructor called" << std::endl;
}

void MateriaSource::learnMateria(AMateria* m)
{
    if (!m)
        return;
    for (int i = 0; i < 4; ++i) {
        if (!inventory[i]) {
            inventory[i] = m;
            std::cout << "MateriaSource: Learned materia of type " << m->getType() << std::endl;
            return;
        }
    }
    std::cout << "MateriaSource: Inventory full, cannot learn more materia" << std::endl;
    delete m;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < 4; ++i) {
        if (inventory[i] && inventory[i]->getType() == type) {
            std::cout << "MateriaSource: Creating materia of type " << type << std::endl;
            return inventory[i]->clone();
        }
    }
    std::cout << "MateriaSource: Materia type " << type << " not found" << std::endl;
    return NULL;
}

