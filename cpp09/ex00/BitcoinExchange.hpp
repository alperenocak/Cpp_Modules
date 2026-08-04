#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>

class  BitcoinExchange
{
private:
    std::map<std::string, float> _values;

public:

    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &other);
    BitcoinExchange &operator=(const BitcoinExchange &other);
    ~BitcoinExchange();

    bool    loadDatabase(const std::string &fname);
    bool    isValidDate(const std::string &dateStr);
    

};



#endif