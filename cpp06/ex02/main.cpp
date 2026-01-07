#include <cstdlib>
#include <ctime>
#include "Base.hpp"
#include "identify.hpp"

int main()
{
    srand(static_cast<unsigned int>(time(NULL)));
    Base* ptr = generate();
    identify(ptr);
    identify(*ptr);
    delete ptr;
    return 0;
}

