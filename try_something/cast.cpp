#include <iostream>
#include <cstdlib> 
#include <string>
#include <iostream>
#include <string>
#include <cstdlib> 
#include <limits>
#include <iomanip>
#include <cctype>    
#include <cmath>
#include <cctype>  
int main()
{
    long long int f = 241666666666666;
    std::cout << std::fixed << std::setprecision(1);
    std::cout << static_cast<double>(f) << std::endl;
}