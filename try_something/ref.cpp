#include <iostream>

void func(const std::string& str)
{
    std::cout << str ;
}

int main()
{
    std::string a = "samet";

    func("alperen");
}