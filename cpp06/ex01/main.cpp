#include "Serialization.hpp"

int main()
{
    Data obj;

    obj.s1 = "alperen";
    obj.s2 = "deneme";
    obj.n  = 42;
    
    std::cout << &obj << std::endl;
    std::cout << Serializer::serialize(&obj) << std::endl;
    uintptr_t adress = Serializer::serialize(&obj);
    std::cout << Serializer::deserialize(adress) << std::endl;
    
    return 0;
}