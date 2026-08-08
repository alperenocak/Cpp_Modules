#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <exception>
class RPN
{
private:
    std::stack<int> _stack;
public:
    class ErrorHandle: public std::exception
    {
       virtual const char *what() const throw();
    };

    int rpnFunciton(const std::string &input);
};


#endif