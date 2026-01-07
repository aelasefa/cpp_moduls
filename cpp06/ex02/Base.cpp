#include <cstdlib>
#include "Base.hpp"

Base* generate(void)
{
    int r = rand() % 3;

    if (r == 0)
        return new A();
    else if (r == 1)
        return new B();
    else
        return new C();
}

Base::~Base(){};
