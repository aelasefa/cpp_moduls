#include "Zombie.hpp"

int main()
{
    int N = 5;
    Zombie* horde = zombieHorde(N, "Default");

    std::string names[5] = {"Alice", "Bob", "Cora", "David", "Eva"};

    for (int i = 0; i < N; i++)
        horde[i].setName(names[i]);

    for (int i = 0; i < N; i++)
    {
        std::cout << "Zombie " << i << ": ";
        horde[i].announce();
    }

    delete[] horde;
}
