#include "Span.hpp"
#include <iostream>
#include <ctime>

int main()
{
    try
    {
        std::srand(std::time(NULL));
        Span sp = Span(5);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;


        std::vector<int> vec; 
        for (int i = 0; i < 10000; i++)
        {
            vec.push_back(std::rand());
        }

        Span span = Span(10000);
        span.addNumbers(vec.begin(), vec.end());
        std::cout << span.shortestSpan() << std::endl;
        std::cout << span.longestSpan() << std::endl;

        return 0;
        
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}