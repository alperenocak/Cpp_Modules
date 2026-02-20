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

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"
class Cat:public Animal
{
private:
    Brain* brain;
public:
    Cat();
    Cat& operator=(const Cat& other);
    Cat(const Cat& other);
    ~Cat();

    virtual void makeSound(void) const;
};



#endif
