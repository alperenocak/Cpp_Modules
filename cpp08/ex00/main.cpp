#include "easyfind.hpp"
#include <vector>
#include <list>
int main()
{
    try {
        std::vector<int> vec;
        vec.push_back(10);
        vec.push_back(20);
        vec.push_back(30);
        std::vector<int>::iterator it = easyfind(vec, 20);
        std::cout << "Value (vector): " << *it << std::endl;
        std::list<int> lst;
        lst.push_back(100);
        lst.push_back(200);
        std::list<int>::iterator lit = easyfind(lst, 200);
        std::cout << "Value (list): " << *lit << std::endl;
        easyfind(vec, 42);
    }
    catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}
