#include "RPN.hpp"
#include <cctype>

int RPN::rpnFunciton(const std::string &input)
{
    if(input.empty())
        throw ErrorHandle();
    int k;
    int l;
    for (size_t i = 0; i < input.size(); i++)
    {
        int digit;
        if (std::isspace(input[i]))
            continue;
        
        if (std::isdigit(input[i]))
        {
            digit = input[i] - '0';
            this->_stack.push(digit);
            
        }
        else if ((input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/'))
        {
            if (this->_stack.size() < 2)
            {
                throw ErrorHandle();
            }
            
            l = _stack.top();
            _stack.pop();
            k = _stack.top();
            _stack.pop();

            if (input[i] == '+')
            {
                _stack.push(k+l);
            }
            else if (input[i] == '-')
            {
                _stack.push(k-l);
            }
            else if (input[i] == '*')
            {
                _stack.push(k *l);
            }
            else if(input[i] == '/')
            {
                if (l == 0)
                {
                    throw ErrorHandle();
                }
                
                _stack.push(k/l);
            }
            
        }
        else
            throw ErrorHandle();
    }
    if (this->_stack.size() != 1)
            throw ErrorHandle();
    return(this->_stack.top());
}

const char *RPN::ErrorHandle::what() const throw()
{
    return "Error";
}
