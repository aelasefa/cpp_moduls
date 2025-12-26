#include "Cat.hpp"
#include <iostream>

Cat::Cat() {
    std::cout << "Cat: Constructor called" << std::endl;
    this->type = "Cat";
}

Cat::Cat(const Cat &other) : Animal(other) {
    std::cout << "Cat: Copy constructor called" << std::endl;
    this->type = other.type;
}

Cat &Cat::operator=(const Cat &other) {
    std::cout << "Cat: Copy assignment operator called" << std::endl;
    if (this != &other) {
        this->type = other.type;
    }
    return *this;
}

Cat::~Cat() {
    std::cout << "Cat: Destructor called" << std::endl;
}

void Cat::makeSound() const {
    std::cout << "Meow!" << std::endl;
}

