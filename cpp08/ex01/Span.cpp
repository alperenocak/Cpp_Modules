#include "Span.hpp"

Span::Span() : _maxLimit(0) {}

Span::Span(unsigned int number) : _maxLimit(number)
{
    _numbers.reserve(number);
}

Span::Span(const Span &other) : _maxLimit(other._maxLimit), _numbers(other._numbers) {}

Span &Span::operator=(const Span &other)
{
    if (this != &other)
    {
        this->_maxLimit = other._maxLimit;
        this->_numbers = other._numbers;
    }
    return *this;
}

Span::~Span() {}

int Span::shortestSpan() const
{
    if (this->_numbers.size() < 2)
        throw NotMoreOne();

    std::vector<int> v = _numbers;
    std::sort(v.begin(), v.end());
    std::vector<int> diff(v.size());
    std::adjacent_difference(v.begin(), v.end(), diff.begin());

    return *std::min_element(diff.begin() + 1, diff.end());
}

int Span::longestSpan() const
{
    if (this->_numbers.size() < 2)
        throw NotMoreOne();

    return (*std::max_element(_numbers.begin(), _numbers.end()) - *std::min_element(_numbers.begin(), _numbers.end()));
}

void Span::addNumber(int number)
{
    if (_numbers.size() >= _maxLimit)
        throw MaxLimit();
    _numbers.push_back(number);
}

const char* Span::MaxLimit::what() const throw()
{
    return "Span is full";
}

const char* Span::NotMoreOne::what() const throw()
{
    return "Span must contain at least two numbers to calculate a span";
}
