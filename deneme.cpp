#include <iomanip>
#include <iostream>

int main()
{

    
    std::string a;
    a = "alperen";

    std::cout<< a.capacity()<<std::endl;
    std::cout<< a.size()<<std::endl;
    
    
    a.reserve(100);
    while (1)
    {
        /* code */
    }
    
    std::cout<< a.capacity()<<std::endl;
}