#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <cctype>

bool isNumber(const std::string& token);
bool isOperator(const std::string& token);
int applyOperator(int a, int b, char op);
#endif
