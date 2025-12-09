#include <iostream>
#include <string>

int main()
{
	std::cout << "-------------------ADDRESS---------------------------------" << std::endl;
	std::string Name = "HI THIS IS BRAIN";

	std::string *ptr = &Name;
	std::string& ref = Name;

	std::cout << "The memory address of the string variable: " << &Name << std::endl;
	std::cout << "The memory address held by stringPTR:      " << ptr << std::endl;
	std::cout << "The memory address held by stringREF:      " << &ref << std::endl;
	std::cout << "-------------------VALUE-----------------------------------" << std::endl;
	std::cout << "The value of the string variable  : " << Name << std::endl;
	std::cout << "The value pointed to by stringPTR : " << *ptr << std::endl;
	std::cout << "The value pointed to by stringREF : " << ref << std::endl;

}

