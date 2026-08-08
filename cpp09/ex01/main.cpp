#include "RPN.hpp"

int main(int ac, char **av)
{
    try
    {
        RPN rpn;
        std::string input = av[1];
        int result = rpn.rpnFunciton(input, rpn);
        return result;   
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}