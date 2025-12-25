
#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat: public Animal {
private:
	std::string type;
public:
	Cat();
	~Cat();
	void makeSound() override
	{
		std::cout << "I'm just animal." << std::endl;
	}
};
#endif
