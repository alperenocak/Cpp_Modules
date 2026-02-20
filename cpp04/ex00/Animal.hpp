/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuocak <yuocak@student.42kocaeli.com.tr>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-02-20 19:38:13 by yuocak            #+#    #+#             */
/*   Updated: 2026-02-20 19:38:13 by yuocak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
class Animal{
protected:
    std::string type;
public:
    Animal();
    Animal& operator=(const Animal& other);
    Animal(const Animal& other);
    virtual ~Animal();
    
    virtual void makeSound(void) const;
    std::string getType(void) const;
};

#endif