#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#define DEBUG_MESSAGES 0

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

	int getHitPoints() const;
	int	getenergyPoint() const;
	int getAttackDamage() const;

	void setAttackDamage(int amount);
	void setHitPoints(int amount);
	void setEnergyPoint(int amount);
};
#endif
