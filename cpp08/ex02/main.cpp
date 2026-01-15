#include <iostream>
#include "MutantStack.hpp"

#include <iostream>
#include <vector>
#include "MutantStack.hpp"

int main()
{
    std::cout << "Testing MutantStack with default container (deque):\n";
    MutantStack<int> mstack;

    std::cout << "Pushing elements: 5, 17\n";
    mstack.push(5);
    mstack.push(17);

    std::cout << "Top element: " << mstack.top() << std::endl;

    mstack.pop();

    std::cout << "Size after pop: " << mstack.size() << std::endl;

    std::cout << "Pushing elements: 3, 5, 737, 0\n";
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    std::cout << "Iterating through MutantStack:\n";
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
    {
        std::cout << *it << std::endl;
    }

    std::cout << "Reverse iterating through MutantStack:\n";
    for (MutantStack<int>::reverse_iterator rit = mstack.rbegin(); rit != mstack.rend(); ++rit)
    {
        std::cout << *rit << std::endl;
    }

    std::cout << "\nTesting MutantStack with std::vector as container:\n";
    MutantStack<int, std::vector<int> > mstackVec;

    std::cout << "Pushing elements: 10, 20, 30\n";
    mstackVec.push(10);
    mstackVec.push(20);
    mstackVec.push(30);

    std::cout << "Top element: " << mstackVec.top() << std::endl;

    std::cout << "Iterating through MutantStack with vector:\n";
    for (MutantStack<int, std::vector<int> >::iterator it = mstackVec.begin(); it != mstackVec.end(); ++it)
    {
        std::cout << *it << std::endl;
    }

    return 0;
}

