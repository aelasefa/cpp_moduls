#include <iostream>
#include <string>
#include "iter.hpp"

void increment(int &n)
{
    n++;
}

void printConstInt(const int &n)
{
    std::cout << n << " ";
}

void printConstString(const std::string &s)
{
    std::cout << s << " ";
}

void addExclamation(std::string &s)
{
    s += "!";
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    const int size = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Original array: ";
    iter(arr, size, printConstInt);
    std::cout << std::endl;

    iter(arr, size, increment);

    std::cout << "After increment: ";
    iter(arr, size, printConstInt);
    std::cout << std::endl;

    std::string strs[] = {"Hello", "world", "C++"};
    const int strSize = sizeof(strs) / sizeof(strs[0]);

    std::cout << "Original strings: ";
    iter(strs, strSize, printConstString);
    std::cout << std::endl;

    iter(strs, strSize, addExclamation);

    std::cout << "After addExclamation: ";
    iter(strs, strSize, printConstString);
    std::cout << std::endl;

    return 0;
}

