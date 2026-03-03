#include <iostream>
class a
{
private:
    /* data */
public:
    a(/* args */);
    ~a();
    class yakaladim:public std::exception{
        public:
            const char *what() const throw();
    };
};

const char* a::yakaladim::what() const throw()
{
    return "a";
}
int main()
{

    try
    {
        throw a::yakaladim();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    
}