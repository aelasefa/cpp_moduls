#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main() {
    const int SIZE = 26;
    Animal* animals[SIZE];

    for (int i = 0; i < SIZE / 2; i++) {
        animals[i] = new Dog();
    }
    for (int i = SIZE / 2; i < SIZE; i++) {
        animals[i] = new Cat();
    }

    std::cout << "\n-- Animals make sounds --\n";
    for (int i = 0; i < SIZE; i++) {
        animals[i]->makeSound();
    }

    std::cout << "\n-- Testing deep copy --\n";
    Dog originalDog;
    Cat originalCat;

    Dog copyDog = originalDog;
    Dog assignedDog;
    assignedDog = originalDog;
    Cat copyCat = originalCat;
    Cat assignedCat;
    assignedCat = originalCat;

    std::cout << "\n-- Cleaning up animals --\n";
    for (int i = 0; i < SIZE; i++) {
        delete animals[i];
    }

    return 0;
}

/*int main() {*/
/*    const Animal* animals[4];*/
/**/
/*    for (int i = 0; i < 2; i++)*/
/*        animals[i] = new Dog();*/
/**/
/*    for (int i = 2; i < 4; i++)*/
/*        animals[i] = new Cat();*/
/**/
/*    for (int i = 0; i < 4; i++)*/
/*        delete animals[i];*/
/**/
/*    return 0;*/
/*}*/
/**/
