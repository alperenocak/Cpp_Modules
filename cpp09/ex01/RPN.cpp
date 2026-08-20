#include "RPN.hpp"
#include <cctype>
#include <sstream>
#include <climits>

RPN::RPN()
{
}

RPN::RPN(const RPN &other) : _stack(other._stack)
{
}

RPN &RPN::operator=(const RPN &other)
{
    if (this != &other)
    {
        this->_stack = other._stack;
    }
    return *this;
}

RPN::~RPN()
{
}

int RPN::calculate(const std::string &input)
{
    if (input.empty())
        throw ErrorHandle();

    while (!_stack.empty())
        _stack.pop();

    std::stringstream ss(input);
    std::string token;
    bool hasToken = false;

    while (ss >> token)
    {
        hasToken = true;
        if (token.length() == 1 && std::isdigit(token[0]))
        {
            _stack.push(token[0] - '0');
        }
        else if (token.length() == 1 && (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/'))
        {
            if (_stack.size() < 2)
                throw ErrorHandle();

            int l = _stack.top();
            _stack.pop();
            int k = _stack.top();
            _stack.pop();

            long long res = 0;
            if (token[0] == '+')
                res = static_cast<long long>(k) + l;
            else if (token[0] == '-')
                res = static_cast<long long>(k) - l;
            else if (token[0] == '*')
                res = static_cast<long long>(k) * l;
            else if (token[0] == '/')
            {
                if (l == 0)
                    throw ErrorHandle();
                res = static_cast<long long>(k) / l;
            }

            if (res > INT_MAX || res < INT_MIN)
                throw ErrorHandle();

            _stack.push(static_cast<int>(res));
        }
        else
        {
            throw ErrorHandle();
        }
    }

    if (!hasToken || _stack.size() != 1)
        throw ErrorHandle();

    return _stack.top();
}

const char *RPN::ErrorHandle::what() const throw()
{
    return "Error";
}
