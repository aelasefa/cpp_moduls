#include "Zombie.hpp"

int main()
{
	int N = 5;
	Zombie* heapZombie = zombieHorde(N,"Heap Zombie");
	for(int i = 0; i < N; i++)
	{
		std::cout << "Zombie " << i << " " ;
		heapZombie[i].announce();
	}
	delete[] (heapZombie);
}
