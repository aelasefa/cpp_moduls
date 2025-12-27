#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria()
{
    std::cout << "AMateria: default constructor called" << std::endl;
}

AMateria::AMateria(std::string const & type) : type(type)
{
    std::cout << "AMateria: param constructor called" << std::endl;
}

AMateria::AMateria(const AMateria &other)
{
    std::cout << "AMateria: copy constructor called" << std::endl;
    this->type = other.type;
}

AMateria &AMateria::operator=(const AMateria &other)
{
    std::cout << "AMateria: copy assignment operator called" << std::endl;
    if (this != &other)
        this->type = other.type;
    return *this;
}

AMateria::~AMateria()
{
    std::cout << "AMateria: destructor called" << std::endl;
}

std::string const & AMateria::getType() const
{
    return this->type;
}

void AMateria::use(ICharacter& target)
{
    (void)target;
}

