#include <iostream>
template <typename T>
void yazdir (T veri)
{
    std::cout << veri << std::endl;
}

int main()
{
    yazdir("alperen");
    yazdir(31);
    yazdir(31.2);
    yazdir(true);
}