#include <iostream>
#include "PmergeMe.hpp"
#include <vector>
#include <deque>
#include <cstdlib>
#include <ctime>
#include <iomanip> 


int main(int argc, char **argv)
{
    try
    {
        std::vector<int> vec;
        parseInput(argc, argv, vec);

        std::deque<int> deq(vec.begin(), vec.end());

        std::cout << GREEN << "Before: " << RESET;
        for (size_t i = 0; i < vec.size(); i++)
        {
            std::cout << vec[i];
            if (i + 1 < vec.size())
                std::cout << " ";
        }
        std::cout << std::endl;

        clock_t start_vec = clock();
        sortVector(vec);
        clock_t end_vec = clock();
        double time_vec = static_cast<double>(end_vec - start_vec) * 1000000 / CLOCKS_PER_SEC;

        clock_t start_deq = clock();
        sortDeque(deq);
        clock_t end_deq = clock();
        double time_deq = static_cast<double>(end_deq - start_deq) * 1000000 / CLOCKS_PER_SEC;

        std::cout << GREEN << "After: " << RESET;
        for (size_t i = 0; i < vec.size(); i++)
        {
            std::cout << vec[i];
            if (i + 1 < vec.size())
                std::cout << " ";
        }
        std::cout << std::endl;

        std::cout << std::fixed << std::setprecision(2);

        std::cout << RED << "Time to process a range of "
                  << vec.size()
                  << " elements with std::vector : "  << RESET
                  << time_vec << " us" << std::endl;

        std::cout << RED << "Time to process a range of "
                  << deq.size()
                  << " elements with std::deque : "  << RESET
                  << time_deq << " us" << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}
