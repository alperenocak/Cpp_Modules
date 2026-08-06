#include "BitcoinExchange.hpp"
#include <fstream>
#include <stdlib.h>
#include <algorithm>
BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other): _values(other._values)
{
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if(this != &other)
    {
        this->_values = other._values;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange()
{
}

bool BitcoinExchange::loadDatabase(const std::string &fname)
{
    std::ifstream file(fname.c_str());
    
    if(!file.is_open())
    {
        std::cerr << "File not open!" << std::endl;
        return false;
    }

    std::string line;
    std::getline(file, line);

    while (std::getline(file,line))
    {
        if(line.empty())
            continue;

        size_t comma = line.find(',');
        if(comma == std::string::npos)
            continue;
        
        std::string strPrice = line.substr(comma + 1);
        std::string date = line.substr(0, comma);
        float price = static_cast<float>(std::atof(strPrice.c_str()));
        _values.insert(std::make_pair(date, price));
    }
    file.close();
    return true;
}

bool BitcoinExchange::isValidDate(const std::string &dateStr)
{
    if (dateStr.size() != 10)
    {
        std::cout << "is not valid not" << std::endl;
        return false;
    }

    if(dateStr[4] != '-' || dateStr[7] != '-')
    {
        std::cout << "tire yok" << std::endl;
        return false;
    }

    if(!std::isdigit(dateStr[0]) || !std::isdigit(dateStr[1]) || !std::isdigit(dateStr[2]) ||
        !std::isdigit(dateStr[3]) || !std::isdigit(dateStr[5]) || !std::isdigit(dateStr[6]) ||
        !std::isdigit(dateStr[8]) || !std::isdigit(dateStr[9]))
    {
        std::cout << "sayi değil" << std::endl;
        return false;
    }

    int day = std::atoi(dateStr.substr(8,2).c_str());
    int month = std::atoi(dateStr.substr(5,2).c_str());
    int year = std::atoi(dateStr.substr(0,4).c_str());

    if(month < 1 || month > 12)
        return false;
    if(day < 1 || day > 31)
        return false;
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
        return false;
    
    if (month == 2)
    {
        bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        if (isLeap && day > 29)
            return false;
        if (!isLeap && day > 28)
            return false;
    }

    return true;
}

bool BitcoinExchange::isValidValue(const std::string &value)
{
    char* end;
    double tmp_value;

    tmp_value = std::strtod(value.c_str(), &end);
    if (*end != '\0' || value.empty())
    {
        std::cerr << "Error: bad input" << std::endl;
        return false;
    }
        
    if(tmp_value < 0)
    {
        std::cerr << "Error: not a positive number" << std::endl;
        return false ;
    }
    
    if (tmp_value > 1000)
    {
        std::cerr << "Error: too large a number" << std::endl;
        return false;
    }
    
    return true;
}