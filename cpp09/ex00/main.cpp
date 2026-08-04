#include "BitcoinExchange.hpp"

int main()
{
    BitcoinExchange file;
    file.loadDatabase("data.csv");
    return 0;
}