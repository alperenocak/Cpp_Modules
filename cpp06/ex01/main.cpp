#include "Serialization.hpp"

int main()
{
    Data obj;

    obj.s1 = "alperen";
    
    std::cout << &obj << std::endl;
    std::cout << Serializer::serialize(&obj) << std::endl;
    uintptr_t adress = Serializer::serialize(&obj);
    std::cout << Serializer::deserialize(adress) << std::endl;

    if (Serializer::deserialize(adress) == &obj)
        std::cout << "Success: Data pointer matches the original address." << std::endl;
    else
        std::cout << "Error: The addresses do not match!" << std::endl;

    return 0;
}