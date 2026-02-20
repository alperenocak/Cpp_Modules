#include "Cat.hpp"

Cat::Cat()
{
    this->type = "Cat";
    std::cout << "Cat default constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
    if (this != &other)
        this->type = other.type;
    std::cout << "Cat copy assignment operator called" << std::endl;
    return (*this);
}

Cat::Cat(const Cat &other) : Animal(other)
{
    *this = other;
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat::~Cat()
{
    std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound(void) const
{
    std::cout << "Meow! Meow!" << std::endl;
}
