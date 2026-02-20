/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuocak <yuocak@student.42kocaeli.com.tr>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-02-20 19:49:12 by yuocak            #+#    #+#             */
/*   Updated: 2026-02-20 19:49:12 by yuocak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"
class Dog: public Animal
{
private:
    Brain* brain;
public:

    Dog();
    Dog& operator=(const Dog& other);
    Dog(const Dog& other);
    ~Dog();

    virtual void makeSound(void) const;

};

#endif