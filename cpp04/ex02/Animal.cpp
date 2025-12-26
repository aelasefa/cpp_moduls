#include "Animal.hpp"
#include <iostream>

Animal::Animal() {
    std::cout << "Animal: Constructor called" << std::endl;
    this->type = "Animal";
}

Animal::Animal(const Animal &other) {
    std::cout << "Animal: Copy constructor called" << std::endl;
    this->type = other.type;
}

Animal &Animal::operator=(const Animal &other) {
    std::cout << "Animal: Copy assignment operator called" << std::endl;
    if (this != &other)
        this->type = other.type;
    return *this;
}

Animal::~Animal() {
    std::cout << "Animal: Destructor called" << std::endl;
}

std::string Animal::getType() const {
    return this->type;
}
