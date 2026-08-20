#include "BitcoinExchange.hpp"
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <cctype>

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : _values(other._values)
{
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this != &other)
    {
        this->_values = other._values;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange()
{
}

std::string BitcoinExchange::trimSpace(const std::string &str) const
{
    size_t first = str.find_first_not_of(" \t");
    if (first == std::string::npos)
        return "";
    size_t last = str.find_last_not_of(" \t");
    return str.substr(first, (last - first + 1));
}

bool BitcoinExchange::isValidDate(const std::string &dateStr) const
{
    if (dateStr.size() != 10)
        return false;

    if (dateStr[4] != '-' || dateStr[7] != '-')
        return false;

    for (size_t i = 0; i < dateStr.size(); ++i)
    {
        if (i == 4 || i == 7)
            continue;
        if (!std::isdigit(dateStr[i]))
            return false;
    }

    int year = std::atoi(dateStr.substr(0, 4).c_str());
    int month = std::atoi(dateStr.substr(5, 2).c_str());
    int day = std::atoi(dateStr.substr(8, 2).c_str());

    if (year < 1000 || month < 1 || month > 12 || day < 1 || day > 31)
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

bool BitcoinExchange::isValidValue(const std::string &value, double &num) const
{
    if (value.empty())
    {
        std::cerr << "Error: bad input => " << value << std::endl;
        return false;
    }

    char* end;
    num = std::strtod(value.c_str(), &end);
    if (*end != '\0')
    {
        std::cerr << "Error: bad input => " << value << std::endl;
        return false;
    }

    if (num < 0)
    {
        std::cerr << "Error: not a positive number." << std::endl;
        return false;
    }

    if (num > 1000)
    {
        std::cerr << "Error: too large a number." << std::endl;
        return false;
    }

    return true;
}

double BitcoinExchange::getRate(const std::string &date) const
{
    if (_values.empty())
        return -1.0;

    const_iterator it = _values.lower_bound(date);

    if (it != this->_values.end() && it->first == date)
        return it->second;

    if (it == this->_values.begin())
        return -1.0;

    --it;
    return it->second;
}

bool BitcoinExchange::loadDatabase(const std::string &fname)
{
    std::ifstream file(fname.c_str());

    if (!file.is_open())
    {
        std::cerr << "Error: could not open file." << std::endl;
        return false;
    }

    std::string line;
    if (!std::getline(file, line))
    {
        file.close();
        return false;
    }

    std::string trimmedLine = trimSpace(line);
    if (trimmedLine != "date,exchange_rate")
    {
        size_t comma = line.find(',');
        if (comma != std::string::npos)
        {
            std::string date = trimSpace(line.substr(0, comma));
            std::string strPrice = trimSpace(line.substr(comma + 1));
            char* end;
            double price = std::strtod(strPrice.c_str(), &end);
            if (isValidDate(date) && *end == '\0' && price >= 0)
                _values[date] = price;
        }
    }

    while (std::getline(file, line))
    {
        if (line.empty())
            continue;

        size_t comma = line.find(',');
        if (comma == std::string::npos)
            continue;

        std::string date = trimSpace(line.substr(0, comma));
        std::string strPrice = trimSpace(line.substr(comma + 1));
        char* end;
        double price = std::strtod(strPrice.c_str(), &end);
        if (isValidDate(date) && *end == '\0' && price >= 0)
            _values[date] = price;
    }
    file.close();
    return true;
}

void BitcoinExchange::processLine(const std::string &line) const
{
    if (line.empty())
        return;

    size_t strpos = line.find('|');
    if (strpos == std::string::npos)
    {
        std::cerr << "Error: bad input => " << line << std::endl;
        return;
    }

    std::string date = trimSpace(line.substr(0, strpos));
    std::string value = trimSpace(line.substr(strpos + 1));

    if (!isValidDate(date))
    {
        std::cerr << "Error: bad input => " << date << std::endl;
        return;
    }

    double num;
    if (!isValidValue(value, num))
        return;

    double rate = getRate(date);
    if (rate < 0)
    {
        std::cerr << "Error: bad input => " << date << std::endl;
        return;
    }

    std::cout << date << " => " << value << " = " << (rate * num) << std::endl;
}

void BitcoinExchange::processInputFile(const std::string &filename) const
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
    {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }

    std::string line;
    if (!std::getline(file, line))
    {
        file.close();
        return;
    }

    std::string trimmedLine = trimSpace(line);
    if (trimmedLine != "date | value")
        processLine(line);

    while (std::getline(file, line))
    {
        processLine(line);
    }
    file.close();
}