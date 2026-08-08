#include "RPN.hpp"

int main(int ac, char **av)
{
    if(ac < 2)
    {
        std::cerr << "you have min two parameters"<<std::endl;
        return 0;
    }

    try
    {
        RPN rpn;
        std::string input = av[1];
        int result = rpn.rpnFunciton(input);
        std::cout << result << std::endl;
        return result;   
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}