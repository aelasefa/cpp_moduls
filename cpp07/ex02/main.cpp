#include <iostream>
#include "Array.hpp"

int main()
{
    try
    {
        Array<int> emptyArray;
        std::cout << "Empty array size: " << emptyArray.size() << std::endl;

        Array<int> numbers(5);
        for (unsigned int i = 0; i < numbers.size(); i++)
            numbers[i] = i * 10;

        std::cout << "Numbers array: ";
        for (unsigned int i = 0; i < numbers.size(); i++)
            std::cout << numbers[i] << " ";
        std::cout << std::endl;

        Array<int> numbersCopy(numbers);
        std::cout << "Copied array: ";
        for (unsigned int i = 0; i < numbersCopy.size(); i++)
            std::cout << numbersCopy[i] << " ";
        std::cout << std::endl;

        Array<int> assignedArray;
        assignedArray = numbers;
        std::cout << "Assigned array: ";
        for (unsigned int i = 0; i < assignedArray.size(); i++)
            std::cout << assignedArray[i] << " ";
        std::cout << std::endl;

        numbers[0] = 999;
        std::cout << "After modification, numbers array: ";
        for (unsigned int i = 0; i < numbers.size(); i++)
            std::cout << numbers[i] << " ";
        std::cout << std::endl;

        std::cout << "Copied array after original modification: ";
        for (unsigned int i = 0; i < numbersCopy.size(); i++)
            std::cout << numbersCopy[i] << " ";
        std::cout << std::endl;

        std::cout << "Accessing out-of-bounds element: " << std::endl;
        std::cout << numbers[10] << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}

