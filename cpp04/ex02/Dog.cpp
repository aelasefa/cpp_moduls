#include "Dog.hpp"
#include <iostream>

Dog::Dog() {
    std::cout << "Dog: Constructor called" << std::endl;
    this->type = "Dog";
}

Dog::Dog(const Dog &other) : Animal(other) {
    std::cout << "Dog: Copy constructor called" << std::endl;
    this->type = other.type;
}

Dog &Dog::operator=(const Dog &other) {
    std::cout << "Dog: Copy assignment operator called" << std::endl;
    if (this != &other) {
        this->type = other.type;
    }
    return *this;
}

Dog::~Dog() {
    std::cout << "Dog: Destructor called" << std::endl;
}

void Dog::makeSound() const {
    std::cout << "Bark!" << std::endl;
}

