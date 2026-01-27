#include <iostream>

void swap(int  &a, int &b)
{
    int tmp = b;

    b = a;
    a = tmp;

}

int main()
{
    int a = 4;
    int b = 3;

    std::cout << "eski a değeri :"<< a << std::endl;
    std::cout <<"eski b değeri : "<< b << std::endl;

    swap(a,b);

    std::cout << "yeni a değeri :"<< a << std::endl;
    std::cout <<"yeni b değeri : "<< b << std::endl;
}