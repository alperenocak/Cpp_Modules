#include <iostream>

class dene
{
    private:
    int a = 5;
    void count(){};
};

int main()
{   
    dene A;
    int *z = (int *)&A;
    *z = 20;
    std::cout << *z << std::endl;
    std::cout << sizeof(dene) << std::endl;
}