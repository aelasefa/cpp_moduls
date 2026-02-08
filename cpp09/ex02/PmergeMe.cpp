#include <string>
#include <stdexcept>
#include <vector>
#include <deque>
#include <algorithm>
#include <cstdlib>
#include <ctime>


bool comparePairs(const std::pair<int, int> &a,
                  const std::pair<int, int> &b)
{
    return a.second < b.second;
}


bool isPositiveNumber(const std::string &s)
{
    if (s.empty())
        return false;

    for (size_t i = 0; i < s.size(); i++)
    {
        if (!isdigit(s[i]))
            return false;
    }
    return true;
}


void parseInput(int argc, char **argv, std::vector<int> &numbers)
{
    for (int i = 1; i < argc; i++)
    {
        std::string arg(argv[i]);

        if (!isPositiveNumber(arg))
            throw std::runtime_error("Error");

        long n = std::atol(arg.c_str());
        if (n < 0 || n > 2147483647)
            throw std::runtime_error("Error");

        numbers.push_back(static_cast<int>(n));
    }

    if (numbers.size() < 2)
        throw std::runtime_error("Error");
}


void sortVector(std::vector<int> &input)
{
    std::vector< std::pair<int, int> > pairs;
    bool hasStraggler = false;
    int straggler = 0;

    size_t i = 0;
    for (; i + 1 < input.size(); i += 2)
    {
        int a = input[i];
        int b = input[i + 1];
        if (a > b)
            std::swap(a, b);
        pairs.push_back(std::make_pair(a, b));
    }

    if (i < input.size())
    {
        hasStraggler = true;
        straggler = input[i];
    }

    std::sort(pairs.begin(), pairs.end(), comparePairs);

    std::vector<int> mainChain;
    for (size_t j = 0; j < pairs.size(); j++)
        mainChain.push_back(pairs[j].second);

    for (size_t j = 0; j < pairs.size(); j++)
    {
        int value = pairs[j].first;
        std::vector<int>::iterator pos =
            std::lower_bound(mainChain.begin(), mainChain.end(), value);
        mainChain.insert(pos, value);
    }

    if (hasStraggler)
    {
        std::vector<int>::iterator pos =
            std::lower_bound(mainChain.begin(), mainChain.end(), straggler);
        mainChain.insert(pos, straggler);
    }

    input = mainChain;
}


void sortDeque(std::deque<int> &input)
{
    std::deque< std::pair<int, int> > pairs;
    bool hasStraggler = false;
    int straggler = 0;

    size_t i = 0;
    for (; i + 1 < input.size(); i += 2)
    {
        int a = input[i];
        int b = input[i + 1];
        if (a > b)
            std::swap(a, b);
        pairs.push_back(std::make_pair(a, b));
    }

    if (i < input.size())
    {
        hasStraggler = true;
        straggler = input[i];
    }

    std::sort(pairs.begin(), pairs.end(), comparePairs);

    std::deque<int> mainChain;
    for (size_t j = 0; j < pairs.size(); j++)
        mainChain.push_back(pairs[j].second);

    for (size_t j = 0; j < pairs.size(); j++)
    {
        int value = pairs[j].first;
        std::deque<int>::iterator pos =
            std::lower_bound(mainChain.begin(), mainChain.end(), value);
        mainChain.insert(pos, value);
    }

    if (hasStraggler)
    {
        std::deque<int>::iterator pos =
            std::lower_bound(mainChain.begin(), mainChain.end(), straggler);
        mainChain.insert(pos, straggler);
    }

    input = mainChain;
}
