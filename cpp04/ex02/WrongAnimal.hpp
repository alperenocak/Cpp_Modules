/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuocak <yuocak@student.42kocaeli.com.tr>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-02-20 21:10:39 by yuocak            #+#    #+#             */
/*   Updated: 2026-02-20 21:10:39 by yuocak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP
#include <iostream>
class WrongAnimal
{
protected:
    std::string type;
public:
    WrongAnimal();
    WrongAnimal& operator=(const WrongAnimal& other);
    WrongAnimal(const WrongAnimal& other);
    ~WrongAnimal();

    void makeSound(void) const;
    std::string getType(void) const;

};



#endif