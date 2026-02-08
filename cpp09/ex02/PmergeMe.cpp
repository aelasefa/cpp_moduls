#include <string>
#include <stdexcept>
#include <vector>
#include <deque>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <utility> 
#include <iterator> 
#include <cassert>

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


static size_t jacobsthal(size_t n)
{
    if (n == 0) return 0;
    if (n == 1) return 1;
    size_t a = 0, b = 1, c;
    for (size_t i = 2; i <= n; ++i)
    {
        c = b + 2 * a;
        a = b;
        b = c;
    }
    return b;
}

static std::vector<size_t> buildJacobOrder(size_t n)
{
    std::vector<size_t> order;
    size_t k = 1;

    while (jacobsthal(k) < n)
    {
        size_t j = jacobsthal(k);
        size_t prev = jacobsthal(k - 1);

        for (size_t i = j; i > prev; --i)
            order.push_back(i - 1);

        ++k;
    }

    return order;
}

template<typename Container, typename PairContainer>
void insertPending(
    Container& mainChain,
    const PairContainer& pairs)
{
    std::vector<size_t> order = buildJacobOrder(pairs.size());
    std::vector<bool> used(pairs.size(), false);

    for (size_t k = 0; k < order.size(); ++k)
    {
        size_t idx = order[k];
        used[idx] = true;

        int small = pairs[idx].first;
        int big   = pairs[idx].second;

        typename Container::iterator partnerPos =
            std::find(mainChain.begin(), mainChain.end(), big);

        typename Container::iterator pos =
            std::lower_bound(mainChain.begin(), partnerPos, small);

        mainChain.insert(pos, small);
    }

    for (size_t idx = 0; idx < pairs.size(); ++idx)
    {
        if (used[idx]) continue;

        int small = pairs[idx].first;
        int big   = pairs[idx].second;

        typename Container::iterator partnerPos =
            std::find(mainChain.begin(), mainChain.end(), big);

        typename Container::iterator pos =
            std::lower_bound(mainChain.begin(), partnerPos, small);

        mainChain.insert(pos, small);
    }
}

template<typename Container>
void fordJohnson(Container& input)
{
    if (input.size() <= 1)
        return;

    typedef std::pair<int,int> IntPair;

    std::vector<IntPair> pairs;
    bool hasStraggler = false;
    int straggler = 0;

    typename Container::size_type i = 0;
    for (; i + 1 < input.size(); i += 2)
    {
        int a = input[i];
        int b = input[i + 1];
        if (a > b) std::swap(a,b);
        pairs.push_back(std::make_pair(a,b));
    }

    if (i < input.size())
    {
        hasStraggler = true;
        straggler = input[i];
    }

    Container mainChain;
    for (size_t j = 0; j < pairs.size(); ++j)
        mainChain.push_back(pairs[j].second);

    fordJohnson(mainChain);

    insertPending(mainChain, pairs);

    if (hasStraggler)
    {
        typename Container::iterator pos =
            std::lower_bound(mainChain.begin(), mainChain.end(), straggler);
        mainChain.insert(pos, straggler);
    }

    input = mainChain;
}

void sortVector(std::vector<int>& vec)
{
    fordJohnson(vec);
}

void sortDeque(std::deque<int>& deq)
{
    fordJohnson(deq);
}
