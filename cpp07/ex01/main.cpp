# include "iter.hpp"

void print(std::string i)
{
    std::cout << i << std::endl;
}

int main()
{
    std::string array[] = {"alperen", "pcak"};
    iter(array, 2, print);
}