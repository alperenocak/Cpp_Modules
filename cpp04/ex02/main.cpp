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

int main()
{
    std::cout << "--- Creating array of Animals ---" << std::endl;
    const int size = 4;
    Animal* animals[size];

    for (int i = 0; i < size / 2; i++)
        animals[i] = new Dog();
    for (int i = size / 2; i < size; i++)
        animals[i] = new Cat();

    std::cout << std::endl << "--- Sounds ---" << std::endl;
    for (int i = 0; i < size; i++)
        animals[i]->makeSound();

    std::cout << std::endl << "--- Deep copy test ---" << std::endl;
    Dog original;
    Dog copy(original);
    std::cout << "original sound: ";
    original.makeSound();
    std::cout << "copy sound: ";
    copy.makeSound();

    std::cout << std::endl << "--- Deleting array ---" << std::endl;
    for (int i = 0; i < size; i++)
        delete animals[i];

    std::cout << std::endl << "--- Scope end (original & copy destruct) ---" << std::endl;
    return 0;
}