#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
class ScalarConverter{
private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter& other);  
    ~ScalarConverter();
    ScalarConverter& operator=(const ScalarConverter& other);
    
    enum e_type{
        CHAR,
        INT,
        FLOAT,
        DOUBLE,
        IMPOSSIBLE
    };
    static  e_type detectType(const std::string& input);

public:
   static void convert(std::string input);
};

#endif
