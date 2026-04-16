#include "Base.hpp"
#include <ctime>

int main()
{
    srand(time(NULL));
    for (int i = 0; i < 4; i++) {
    Base* p = generate();
    if (p) {
        std::cout << "Test " << i + 1 << ":" << std::endl;
        identify(p);  
        identify(*p);
        delete p;  
        std::cout << "------------------" << std::endl;
    }
    }    
}