#include <iostream>
class a
{
private:
/* data */
public:
int v  = 2;
int n = 1; 
    void func();
    a(/* args */);
    ~a();
};

a::a(/* args */)
{
}

a::~a()
{
}


void a::func()
{   
    a c;

    std::cout << this << std::endl; 
    std::cout << &c << std::endl; 

}

int main()
{
    a b;
    b.func();
    std::cout << &b << std::endl;
    std::cout << &b.n << std::endl;
    std::cout << &b.v << std::endl;

    
}