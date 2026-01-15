#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <iterator> 
#include <stdexcept>  
class Span
{
private:
    unsigned int _maxSize;
    std::vector<int> _numbers;

public:
    Span(unsigned int N);
    Span(const Span &other);
    Span &operator=(const Span &other);
    ~Span();

    void addNumber(int number);
    int shortestSpan() const;
    int longestSpan() const;

    template <typename InputIt>
    void addNumbers(InputIt begin, InputIt end)
    {
        size_t rangeSize = std::distance(begin, end);
        if (_numbers.size() + rangeSize > _maxSize)
            throw std::runtime_error("Span capacity exceeded");
        _numbers.insert(_numbers.end(), begin, end);
    }
};

#endif

