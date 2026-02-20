/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuocak <yuocak@student.42kocaeli.com.tr>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-02-20 19:34:11 by yuocak            #+#    #+#             */
/*   Updated: 2026-02-20 19:34:11 by yuocak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    std::cout << "-------Constructor-----------"<<std::endl;
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << "-------WrongCat Constructor-----------"<<std::endl;
    const WrongAnimal *a = new WrongCat();

    std::cout << "\n-------Types-----------"<<std::endl;
    std::cout << j->getType() << " :Dog" << std::endl;
    std::cout << i->getType() << " :Cat" << std::endl;
    std::cout << meta->getType() << " :Animal" << std::endl;


    std::cout << "\n-------Cat Sounds-----------"<<std::endl;
    i->makeSound();
    std::cout << "-------Dog Sounds-----------"<<std::endl;
    j->makeSound();
    std::cout << "-------Animal Sounds-----------"<<std::endl;
    meta->makeSound();
    std::cout << "-------WrongCat Sounds-----------"<<std::endl;
    a->makeSound();

    std::cout << "\n-------Destructor-----------"<<std::endl;
    delete meta;
    delete i;
    delete j;
    delete a;
    return (0);
}