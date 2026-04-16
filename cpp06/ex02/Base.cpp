#include "Base.hpp"

Base::~Base(){}

Base* generate(void)
{
    int r = rand() % 100;

    if (r < 10)
        return new A();
    else if(r < 40)
        return new B();
    else
        return new C();
}

void identify(Base *p)
{
    if(dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if(dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;

}

void identify(Base &p)
{
    try
    {
        A& a = dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        (void)a;
    }
    catch(...)
    {
        std::cerr << "This is not A" << '\n';
    }
    try
    {
        B& b = dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        (void)b;
    }
    catch(...)
    {
        std::cerr << "This is not B" << '\n';
    }
    try
    {
        C& c = dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        (void)c;
    }
    catch(...)
    {
        std::cerr << "This is not C"<< '\n';
    }
}
