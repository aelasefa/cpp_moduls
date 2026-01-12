#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

int main()
{
	try
	{
		std::vector<int> vec;
		vec.push_back(1);
		vec.push_back(3);
		vec.push_back(5);
		vec.push_back(7);
		vec.push_back(9);
		std::cout << "Searching 5 in vector..." << std::endl;
		easyfind(vec, 5);
		std::cout << "Found 5 in vector!" << std::endl;

		std::cout << "Searching 2 in vector..." << std::endl;
		easyfind(vec, 2);
		std::cout << "Found 2 in vector!" << std::endl; 
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	try
	{
		std::list<int> lst;
		lst.push_back(10);
		lst.push_back(20);
		lst.push_back(30);
		std::cout << "Searching 20 in list..." << std::endl;
		easyfind(lst, 20);
		std::cout << "Found 20 in list!" << std::endl;

		std::cout << "Searching 40 in list..." << std::endl;
		easyfind(lst, 40);
		std::cout << "Found 40 in list!" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}

