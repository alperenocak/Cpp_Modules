/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuocak <yuocak@student.42kocaeli.com.tr>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-02-20 19:49:14 by yuocak            #+#    #+#             */
/*   Updated: 2026-02-20 19:49:14 by yuocak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Cat:public Animal
{

public:
    
    Cat();
    Cat& operator=(const Cat& other);
    Cat(const Cat& other);
    ~Cat();
};



#endif
