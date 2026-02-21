/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuocak <yuocak@student.42kocaeli.com.tr>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-02-20 22:59:51 by yuocak            #+#    #+#             */
/*   Updated: 2026-02-20 22:59:51 by yuocak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
    this->type = "Cat";
    this->brain = new Brain;
    std::cout << "Cat default constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
    if (this != &other)
    {
        if (this->brain)
        {
            delete this->brain;
        }
        this->brain =new Brain;
        *this->brain = *other.brain;
        this->type = other.type;
    }
    std::cout << "Cat copy assignment operator called" << std::endl;
    return (*this);
}

Cat::Cat(const Cat &other) : Animal(other), brain(NULL)
{
    *this = other;
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat::~Cat()
{
    std::cout << "Cat destructor called" << std::endl;
    delete brain;
}

void Cat::makeSound(void) const
{
    std::cout << "Meow! Meow!" << std::endl;
}
