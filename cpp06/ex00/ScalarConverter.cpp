#include "ScalarConverter.hpp"
#include <cctype>
#include <iomanip>
void ScalarConverter:: convert(std::string input)
{
    if(input.length() == 1 && !std::isdigit(input[0]))
    {
        std::cout << "char: " << "'" <<input[0] << "'" << std::endl;
        std::cout << "int: "<< static_cast<int>(input[0]) << std::endl;
        std::cout << std::fixed << std::setprecision(1);
        std::cout << "float: " << static_cast<float>(input[0])<< "f" << std::endl;
        std::cout << "double: "<< static_cast<double>(input[0]) << std::endl;
        std::cout << std::defaultfloat;
    }
    else if()
}