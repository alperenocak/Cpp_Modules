#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <iterator>
# include <algorithm>
# include <numeric>
# include <exception>

class Span
{
private:
    unsigned int        _maxLimit;
    std::vector<int>    _numbers;
public:
    class MaxLimit : public std::exception {
    public:
        virtual const char* what() const throw();
    };
    
    class NotMoreOne : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    Span();
    Span(unsigned int N);
    Span(const Span &other);
    Span &operator=(const Span &other);
    ~Span();

    int shortestSpan() const;
    int longestSpan() const;
    void addNumber(int number);

    template <typename InputIterator>
    void addNumbers(InputIterator begin, InputIterator end);
};

template <typename InputIterator>
void Span::addNumbers(InputIterator begin, InputIterator end)
{
    unsigned int count = std::distance(begin, end);

    if (_numbers.size() + count > _maxLimit)
        throw MaxLimit();
    _numbers.insert(_numbers.end(), begin, end);
}

#endif