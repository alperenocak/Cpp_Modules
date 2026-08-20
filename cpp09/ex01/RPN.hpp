#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <string>
#include <exception>

class RPN
{
private:
    std::stack<int> _stack;

public:
    class ErrorHandle : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };

    RPN();
    RPN(const RPN &other);
    RPN &operator=(const RPN &other);
    ~RPN();

    int calculate(const std::string &input);
};

#endif