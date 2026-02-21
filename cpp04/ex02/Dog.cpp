/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuocak <yuocak@student.42kocaeli.com.tr>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-02-20 20:07:03 by yuocak            #+#    #+#             */
/*   Updated: 2026-02-20 20:07:03 by yuocak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
    this->type = "Dog";
    this->brain = new Brain;
    std::cout << "Dog default constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
    if (this != &other)
    {
        if(this->brain)
        {
            delete this->brain;
        }
        this->brain = new Brain;
        *(this->brain) = *(other.brain);
        this->type = other.type;
    }
    std::cout << "Dog copy assignment operator called" << std::endl;
    return (*this);
}

Dog::Dog(const Dog &other) : Animal(other), brain(NULL)
{
    *this = other;
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
    delete this->brain;
}

void Dog::makeSound(void) const
{
    std::cout << "Woof! Woof!" << std::endl;
}
