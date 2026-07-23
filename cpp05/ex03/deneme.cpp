#include <iostream>
class a
{
private:

public:
    
    virtual void deneme();
    virtual ~a();
};


class b : public a

{
private:
    /* data */
public:
int b;
    void deneme();
    ~b();
};

int main()
{
    std::cout << sizeof(a) << std::endl;
    std::cout << sizeof(b) << std::endl;
}