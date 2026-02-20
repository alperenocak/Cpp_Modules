/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuocak <yuocak@student.42kocaeli.com.tr>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-02-20 22:59:54 by yuocak            #+#    #+#             */
/*   Updated: 2026-02-20 22:59:54 by yuocak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Brain.hpp"

Brain::Brain()
{

    std::cout << "Brain default constructor called" << std::endl;
}

Brain &Brain::operator=(const Brain &other)
{
    if (this != &other)
    {
        for (int i = 0; i < 100; i++)
            this->ideas[i] = other.ideas[i];
    }
    std::cout << "Brain copy assignment operator called" << std::endl;
    return (*this);
}

Brain::Brain(const Brain &other)
{
    *this = other;
    std::cout << "Brain copy constructor called" << std::endl;
}

Brain::~Brain()
{
    std::cout << "Brain destructor called" << std::endl;
}
