#include "ScalarConverter.hpp"
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <climits>

std::string CheckInput(const std::string &input)
{
    if (input.length() == 1)
    {
        if (isprint(input[0]) && !isdigit(input[0]))
            return "char";
    }

    if (input == "nanf" || input == "+inff" || input == "-inff")
        return "float";

    if (input == "nan" || input == "+inf" || input == "-inf")
        return "double";

    int i = 0;

    if (input[i] == '+' || input[i] == '-')
        i++;

    if (i == (int)input.length())
        return "unknown";

    bool allDigits = true;
    for (int j = i; j < (int)input.length(); j++)
    {
        if (!isdigit(input[j]))
        {
            allDigits = false;
            break;
        }
    }

    if (allDigits)
        return "int";

    i = 0;
    int dotCount = 0;

    if (input[i] == '+' || input[i] == '-')
        i++;

    while (i < (int)input.length() - 1)
    {
        if (isdigit(input[i]))
            ;
        else if (input[i] == '.')
            dotCount++;
        else
            return "unknown";
        i++;
    }

    if (input[input.length() -1] == 'f' && dotCount == 1)
        return "float";

    i = 0;
    dotCount = 0;

    if (input[i] == '+' || input[i] == '-')
        i++;

    while (i < (int)input.length())
    {
        if (isdigit(input[i]))
            ;
        else if (input[i] == '.')
            dotCount++;
        else
            return "unknown";
        i++;
    }

    if (dotCount == 1)
        return "double";

    return "unknown";
}


void ScalarConverter::convert(const std::string &input)
{
    std::string type = CheckInput(input);
    double base = 0;

    // ---------- CHAR ----------
    if (type == "char")
    {
        char c = input[0];
        base = static_cast<double>(c);
    }
    // ---------- INT ----------
    else if (type == "int")
    {
        long n = std::strtol(input.c_str(), NULL, 10);
        base = static_cast<double>(n);
    }
    // ---------- FLOAT ----------
    else if (type == "float")
    {
        float f = std::strtof(input.c_str(), NULL);
        base = static_cast<double>(f);
    }
    // ---------- DOUBLE ----------
    else if (type == "double")
    {
        base = std::strtod(input.c_str(), NULL);
    }
    else
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        return;
    }

    // ---------- PRINT CHAR ----------
    if (std::isnan(base) || base < 0 || base > 127)
        std::cout << "char: impossible" << std::endl;
    else if (!std::isprint(static_cast<int>(base)))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(base) << "'" << std::endl;

    // ---------- PRINT INT ----------
    if (std::isnan(base) || base < INT_MIN || base > INT_MAX)
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(base) << std::endl;

    // ---------- PRINT FLOAT ----------
    float f = static_cast<float>(base);
    std::cout << "float: " << f;
    if (f - static_cast<int>(f) == 0)
        std::cout << ".0";
    std::cout << "f" << std::endl;

    // ---------- PRINT DOUBLE ----------
    std::cout << "double: " << base;
    if (base - static_cast<int>(base) == 0)
        std::cout << ".0";
    std::cout << std::endl;
}

