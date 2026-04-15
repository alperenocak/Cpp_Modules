#ifndef SERIALIZATION_HPP
#define SERIALIZATION_HPP

#include <cstdint>
#include <iostream>
struct Data
{
    std::string s1;
    int         n;
    std::string s2;
};


class Serialization
{
private:
    
    Serialization();
    Serialization(const Serialization& other);
    ~Serialization();
    Serialization& operator=(const Serialization& other);
    
     
public:
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
};

#endif
