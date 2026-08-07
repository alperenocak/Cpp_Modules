#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>

class  BitcoinExchange
{
private:
    std::map<std::string, float> _values;

public:

    typedef std::map<std::string, float>::const_iterator const_iterator;

    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &other);
    BitcoinExchange &operator=(const BitcoinExchange &other);
    ~BitcoinExchange();
    
    std::string trimSpace(const std::string &str);
    bool    loadDatabase(const std::string &fname);
    bool    isValidDate(const std::string &dateStr);
    bool    isValidValue(const std::string &value);
    float   getRate(const std::string &date);
    void    processInputFile(const std::string &filename);

};



#endif