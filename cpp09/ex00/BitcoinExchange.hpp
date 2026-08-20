#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <string>

class BitcoinExchange
{
private:
    std::map<std::string, double> _values;

    std::string trimSpace(const std::string &str) const;
    bool isValidDate(const std::string &dateStr) const;
    bool isValidValue(const std::string &value, double &num) const;
    double getRate(const std::string &date) const;
    void processLine(const std::string &line) const;

public:
    typedef std::map<std::string, double>::const_iterator const_iterator;

    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &other);
    BitcoinExchange &operator=(const BitcoinExchange &other);
    ~BitcoinExchange();
    
    bool loadDatabase(const std::string &fname);
    void processInputFile(const std::string &filename) const;
};

#endif