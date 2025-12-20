#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#define DEBUG_MESSAGES 1

class ClapTrap {
private:
	std::string _name;
	int			_hitPoints;
	int			_energyPoint;
	int			_attackDamage;
public:
	ClapTrap();
	ClapTrap(const std::string &name);
	ClapTrap(const ClapTrap &other);
	ClapTrap &operator=(const ClapTrap &obj);
	~ClapTrap();

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};
#endif
