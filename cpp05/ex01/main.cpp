#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
    try
    {
        Bureaucrat a("Alperen", 1);
        Form f("TaxForm", 50, 25);
        std::cout << a;
        std::cout << f;
        a.signForm(f);
        std::cout << f;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        Bureaucrat b("Bob", 100);
        Form f2("SecretForm", 10, 5);
        std::cout << b;
        b.signForm(f2);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        Bureaucrat c("Invalid", 0);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        Form f3("BadForm", 0, 10);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}