#include "RPN.hpp"
#include <cctype>

int RPN::rpnFunciton(const std::string &input, RPN rpn)
{
    if(input.empty())
        throw ErrorHandle();
    
    for (int i = 0; i < input.size(); i++)
    {
        int digit;
        if (std::isspace(input[i]))
            continue;
        
        if (std::isdigit(input[i]))
        {
            digit = input[i] - '0';
            this->stack.push(digit);
        }
        
    }
    
    
    
}

const char *RPN::ErrorHandle::what() const throw()
{
    return "Error";
}
