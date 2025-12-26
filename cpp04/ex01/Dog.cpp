#include "Dog.hpp"
#include <iostream>

Dog::Dog() : brain(new Brain()) {
    std::cout << "Dog: Constructor called" << std::endl;
    type = "Dog";
}

Dog::Dog(const Dog &other) : Animal(other) {
    std::cout << "Dog: Copy constructor called" << std::endl;
    brain = new Brain(*other.brain);
}

Dog &Dog::operator=(const Dog &other) {
    std::cout << "Dog: Copy assignment operator called" << std::endl;
    if (this != &other) {
        Animal::operator=(other);
        delete brain;
        brain = new Brain(*other.brain);
    }
    return *this;
}

Dog::~Dog() {
    std::cout << "Dog: Destructor called" << std::endl;
    delete brain;
}

void Dog::makeSound() const {
    std::cout << "Bark!" << std::endl;
}

