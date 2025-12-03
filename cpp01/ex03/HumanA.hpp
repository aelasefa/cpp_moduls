#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA {
    private:
        Weapon &wp;
        std::string name;
    public:
        HumanA(const std::string &va, Weapon &wa);
        ~HumanA();
        void attack() const;
};

#endif
