/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuocak <yuocak@student.42kocaeli.com.tr>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-02-20 21:09:25 by yuocak            #+#    #+#             */
/*   Updated: 2026-02-20 21:09:25 by yuocak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include <iostream>
#include "WrongAnimal.hpp"

class WrongCat:public WrongAnimal
{ 
public:
    WrongCat();
    WrongCat& operator=(const WrongCat& other);
    WrongCat(const WrongCat& other);
    ~WrongCat();

    void makeSound(void) const;
};



#endif