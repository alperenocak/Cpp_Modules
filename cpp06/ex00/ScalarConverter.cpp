#include "ScalarConverter.hpp"
#include <iostream>
#include <string>
#include <cstdlib> 
#include <limits>
#include <iomanip>
#include <cctype>    
#include <cmath>


ScalarConverter::ScalarConverter(){}

ScalarConverter::ScalarConverter(const ScalarConverter &other){
    *this = other;
}

ScalarConverter::~ScalarConverter(){}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other){
    (void)other;
    return *this;
}


void ScalarConverter:: convert(std::string input)
{
    e_type type = detectType(input);

    switch (type)
    {
        case CHAR:
        {
            char c = input[0];
            std::cout << "char: " << "'" << c << "'" << std::endl;
            std::cout << "int: "<< static_cast<int>(c) << std::endl;
            std::cout << std::fixed << std::setprecision(1);
            std::cout << "float: " << static_cast<float>(c)<< "f" << std::endl;
            std::cout << "double: "<< static_cast<double>(c) << std::endl;
            std::cout.unsetf(std::ios_base::floatfield);
            break;
        }
        case INT:
        {
            int i = std::atoi(input.c_str());
            if (i < std::numeric_limits<char>::min() || i > std::numeric_limits<char>::max())
            {
                std::cout << "char: impossible" << std::endl;
            }
            else if(!std::isprint(i))
            {
                std::cout << "char: Non displayable" << std::endl;
            }
            else
            {
                std::cout << "char: " << "'" << static_cast<char>(i) << "'" << std::endl;
            }
            std::cout << "int: "<< i << std::endl;
            std::cout << std::fixed << std::setprecision(1);
            std::cout << "float: " << static_cast<float>(i)<< "f" << std::endl;
            std::cout << "double: "<< static_cast<double>(i) << std::endl;
            std::cout.unsetf(std::ios_base::floatfield);
            break;
        }
        case DOUBLE:
        {
            double d = std::strtod(input.c_str(), NULL);
            if(d != d || d < std::numeric_limits<char>::min() || d > std::numeric_limits<char>::max())
            {
                std::cout << "char: impossible" << std::endl;
            }
            else if (!std::isprint(static_cast<int>(d)))
            {
                std::cout << "char: Non displayable" << std::endl;            
            }
            else
            {
                std::cout << "char: " << "'" << static_cast<char>(d) << "'" << std::endl;
            }
            if(d != d || d < std::numeric_limits<int>:: min() || d > std::numeric_limits<int>::max())
            {
                std::cout << "int: impossible" << std::endl;
            }
            else
            {
                std::cout << "int: " << static_cast<int>(d) << std::endl;
            } 
            std::cout << std::fixed << std::setprecision(1);
            std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
            std::cout << "double: " << d << std::endl;
            std::cout.unsetf(std::ios_base::floatfield);
            break;
        }
        case FLOAT:
        {
            float f = static_cast<float>(std::strtod(input.c_str(), NULL));
            if(f != f || f < std::numeric_limits<char>::min() ||  f > std::numeric_limits<char>::max())
            {
                std::cout << "char: impossible" << std::endl;    
            }
            else if(!std::isprint(static_cast<int>(f)))
            {
                std::cout << "char: Non displayable" << std::endl;            
            }
            else
            {
                std::cout << "char: " << "'" << static_cast<char>(f) << "'" << std::endl;
            }
            if(f != f || f < std::numeric_limits<int>::min() || f > std::numeric_limits<int>::max())
            {
                std::cout << "int: impossible" << std::endl;
            }
            else 
            {
                std::cout << "int: " << static_cast<int>(f) << std::endl;
            }
            
            std::cout << std::fixed << std::setprecision(1);
            std::cout << "float: " << f << "f" << std::endl;
            std::cout << "double: " << static_cast<double>(f) << std::endl;
            std::cout.unsetf(std::ios_base::floatfield);
            break;
        }
        case IMPOSSIBLE:
        {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: impossible" << std::endl;
            std::cout << "double: impossible" << std::endl;
            break; 
        }
    }
}


ScalarConverter::e_type ScalarConverter::detectType(const std::string &input)
{
    if(input == "nan" || input == "+inf" || input == "-inf")
        return DOUBLE;
    if(input == "nanf" || input == "+inff" || input == "-inff")
        return FLOAT;
    if (input.length() == 1 && !std::isdigit(input[0]))
        return CHAR;
    
    char    *endptr = NULL;
    double  val = 0;

    val = std::strtod(input.c_str(), &endptr);

    if(*endptr == '\0')
    {
        if (input.find('.') != std::string::npos)
            return DOUBLE;
        else
            return INT;
    }
    if ((*endptr == 'f' || *endptr == 'F') && endptr[1] == '\0')
        return FLOAT;
    
    return IMPOSSIBLE;
}
