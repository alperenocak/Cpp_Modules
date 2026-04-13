#include "ScalarConverter.hpp"
#include <iostream>
#include <string>
#include <cstdlib> 
#include <limits>
#include <iomanip>
#include <cctype>    

void ScalarConverter:: convert(std::string input)
{
    double  val = 0;
    char    *endptr = NULL;

    if(input.length() == 1 && !std::isdigit(input[0]))
    {
        std::cout << "char: " << "'" <<input[0] << "'" << std::endl;
        std::cout << "int: "<< static_cast<int>(input[0]) << std::endl;
        std::cout << std::fixed << std::setprecision(1);
        std::cout << "float: " << static_cast<float>(input[0])<< "f" << std::endl;
        std::cout << "double: "<< static_cast<double>(input[0]) << std::endl;
        return;
    }

    //DOUBLE veya float gelirse burda kotnrol edip convert ediyoruz 

    val = strtod(input.c_str(), &endptr);
    if (*endptr == '\0')
    {
        std::cout << "bu bir double" << std::endl;
    }
    else if((*endptr == 'f' || *endptr == 'F') && endptr[1] == '\0')
    {
        std::cout << "bu bir float" << std::endl;
    }
    else{
        std::cout << "geçersiz"<< std::endl;
        return;
    }
    //INT YAZDIR
    if (val!= val || val < std::numeric_limits<int>::min() || val > std::numeric_limits<int>::max())
    {
        std::cout << "int değerleri arasında değil";
    }
    else
    {
        std::cout << "int: " << static_cast<int>(val) << std::endl;
    }
    //CHAR YAZDIR
    if (val != val || val < std::numeric_limits<char>::min() || val > std::numeric_limits<char>::max())
    {
        std::cout << "char: impossible" << std::endl;
    }
    else if (!isprint(val))
    {
        std::cout << "non displayable" << std::endl;
    }

    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << static_cast<float>(val) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(val) << std::endl;
}


