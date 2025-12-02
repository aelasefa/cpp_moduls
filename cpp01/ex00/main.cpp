#include "Zombie.hpp"

int main()
{
    std::cout << "Creating a new Zombie on the stack..." << std::endl;
    randomChump("Stack zombie");

    std::cout << "Creating a new Zombie on the heap..." << std::endl;
    Zombie* heapZombie = newZombie("Heap Zombie");
    heapZombie->announce();

    delete heapZombie;
}
