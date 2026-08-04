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

    if(dateStr[4] != '-' && dateStr[7] != '-')
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
}
