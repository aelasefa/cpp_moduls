#include <iostream>
#include <sstream>
#include <string>
#include <stack>
#include <cctype>

bool isNumber(const std::string& token)
{
    return token.length() == 1 && isdigit(token[0]);
}

bool isOperator(const std::string& token)
{
    return token.length() == 1 &&
           (token[0] == '+' || token[0] == '-' ||
            token[0] == '*' || token[0] == '/');
}

int applyOperator(int a, int b, char op)
{
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    if (op == '*') return a * b;
    if (op == '/')
    {
        if (b == 0)
            throw std::runtime_error("Error");
        return a / b;
    }
    throw std::runtime_error("Error");
}

