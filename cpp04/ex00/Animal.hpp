#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal {
protected:
	std::string type;
public:
	Animal();
	virtual void makeSound()
	{
		std::cout << type << std::endl;
	}
	std::string getType() const;
	virtual ~Animal();
};
#endif
