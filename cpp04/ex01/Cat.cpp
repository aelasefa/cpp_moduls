#include "Cat.hpp"
#include <iostream>

Cat::Cat() : brain(new Brain()) {
    std::cout << "Cat: Constructor called" << std::endl;
    type = "Cat";
}

Cat::Cat(const Cat &other) : Animal(other) {
    std::cout << "Cat: Copy constructor called" << std::endl;
    brain = new Brain(*other.brain);
}

Cat &Cat::operator=(const Cat &other) {
    std::cout << "Cat: Copy assignment operator called" << std::endl;
    if (this != &other) {
        Animal::operator=(other);
        delete brain;
        brain = new Brain(*other.brain);
    }
    return *this;
}

Cat::~Cat() {
    std::cout << "Cat: Destructor called" << std::endl;
    delete brain;
}

void Cat::makeSound() const {
    std::cout << "Meow!" << std::endl;
}

