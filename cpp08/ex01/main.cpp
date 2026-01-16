#include <iostream>
#include <vector>
#include "Span.hpp"

int main()
{
    try
    {
        std::vector<int> nums;
        nums.push_back(6);
        nums.push_back(3);
        nums.push_back(17);
        nums.push_back(9);
        nums.push_back(11);

        Span sp(5);

        std::cout << "Adding a range of numbers: 6, 3, 17, 9, 11\n";
        sp.addNumbers(nums.begin(), nums.end());

        std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << sp.longestSpan() << std::endl;

        std::cout << "Trying to add another number (should throw)...\n";
        sp.addNumber(42);
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    try
    {
        Span sp2(1);
        sp2.addNumber(10);
        std::cout << "Trying shortestSpan on Span with 1 number (should throw)...\n";
        std::cout << sp2.shortestSpan() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    try
    {
        Span sp3(0);
        std::cout << "Trying longestSpan on empty Span (should throw)...\n";
        std::cout << sp3.longestSpan() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}

