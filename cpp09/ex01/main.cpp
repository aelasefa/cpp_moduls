#include "RPN.hpp"
#include <stack>
#include <iostream>
#include <sstream>
#include <stack>

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    std::stack<int> stack;
    std::stringstream ss(argv[1]);
    std::string token;

    try
    {
        while (ss >> token)
        {
            if (isNumber(token))
            {
                stack.push(token[0] - '0');
            }
            else if (isOperator(token))
            {
                if (stack.size() < 2)
                    throw std::runtime_error("Error");

                int b = stack.top(); stack.pop();
                int a = stack.top(); stack.pop();

                int result = applyOperator(a, b, token[0]);
                stack.push(result);
            }
            else
                throw std::runtime_error("Error");
        }

        if (stack.size() != 1)
            throw std::runtime_error("Error");

        std::cout << stack.top() << std::endl;
    }
    catch (...)
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    return 0;
}

