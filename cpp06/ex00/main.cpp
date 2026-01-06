#include <iostream>


int main(int ac, char **av)
{
	(void)av;
	if (ac != 2)
	{
		std::cout << "Error" << std::endl;
		return 1;
	}
	CheckInput(av[1]);
}
