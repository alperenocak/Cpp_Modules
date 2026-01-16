/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuocak <yuocak@student.42kocaeli.com.tr>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-01-09 13:46:48 by yuocak            #+#    #+#             */
/*   Updated: 2026-01-09 13:46:48 by yuocak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook()
{
    _index = 0;
    _count = 0;
    
}

PhoneBook::~PhoneBook()
{
}

void PhoneBook::addContact()
{
    std::string input;

    std::cout<<"First Name: ";
    std::getline(std::cin, input);
    _persons[_index].setFirst(input);

    std::cout<<"Last Name: ";
    std::getline(std::cin, input);
    _persons[_index].setLast(input);

    std::cout<<"Nickname: ";
    std::getline(std::cin, input);
    _persons[_index].setNick(input);

    std::cout<<"Phone Number: ";
    std::getline(std::cin, input);
    _persons[_index].setPhone(input);

    std::cout<<"Dark Secret: ";
    std::getline(std::cin, input);
    _persons[_index].setSecret(input);

    if (_count < 8)
        _count++;

    if(_index == 8)
        _index = 0;
}

void PhoneBook::searchContact() const
{
    if (_count == 0)
    {
        std::cout<<"PhoneBook is empty"<<std::endl;
        return ;
    }

    std::cout<<"| index | first | last | nick |"<<std::endl;
    
    for (int i = 0; i < _count; i++)
    {
        std::cout<< "|";
        std::cout<< _persons[i].getFirst();
        std::cout<< "|";
        std::cout<< _persons[i].getLast();
        std::cout<< "|";
        std::cout<< _persons[i].getNick();
        std::cout<< "|";
        std::cout<< _persons[i].getPhone();
        std::cout<< "|"<<std::endl;
    }
    

    return ;

}


// ✅ Önce tabloyu yaz
// ✅ SONRA index inputu al
// ✅ SONRA o index’teki bilgileri çek