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

std::string trim_string(std::string value)
{
    std::string new_value;

    if((int)value.length() > 10)
    {
        for (int i = 0; i < 9; i++)
        {
            new_value += value[i];
        }
        new_value += '.';
        return(new_value);
    }
    return(value);
}

void PhoneBook::addContact()
{
    std::string input;
    
    std::cout<<"First Name: ";
    if(!std::getline(std::cin, input))
        return;
    
    _persons[_index].setFirst(input);

    std::cout<<"Last Name: ";
    if(!std::getline(std::cin, input))
        return;
    _persons[_index].setLast(input);

    std::cout<<"Nickname: ";
    if(!std::getline(std::cin, input))
        return ;
    _persons[_index].setNick(input);

    
    std::cout<<"Phone Number: ";
    if(!std::getline(std::cin, input))
        return ;
    _persons[_index].setPhone(input);

    std::cout<<"Dark Secret: ";
    if (!std::getline(std::cin, input))
        return;
    _persons[_index].setSecret(input);

    if (_count < 8)
        _count++;
    _index++;
    if(_index == 8)
        _index = 0;
}

bool invalid_input(std::string input)
{
    int i = 0;
    while (input[i])
    {
        if('0' >= input[i] && input[i] >= '9')
            return 1;
        i++;
    }
    return 0;
}


void PhoneBook::searchContact() const
{
    if (_count == 0)
    {
        std::cout<<"PhoneBook is empty"<<std::endl;
        return ;
    }
    
    std::cout<<"|     index|     first|      last|      nick|"<<std::endl;
    std::cout<<"|-------------------------------------------|"<<std::endl;
    for (int i = 0; i < _count; i++)
    {
        std::cout<< "|"
        << std::setw(10) << _index - 1 
        << "|"
        << std::setw(10)<< trim_string(_persons[i].getFirst())
        << "|"
        << std::setw(10)<< trim_string(_persons[i].getLast())
        << "|"
        << std::setw(10)<<  trim_string(_persons[i].getNick())
        << "|"<< std::endl;
        std::cout<<"|-------------------------------------------|"<<std::endl;
    }
    /*------------------------------------------------------------*/
    std::string input;

    if (!getline(std::cin, input))
        return ;
    if (input.empty())
    {
        std::cout<<"Write something!!!!!!!!!!!"<<std::endl;
        return ;
    }
    if (invalid_input(input))
    {
        std::cout<<"Invalid input"<< std::endl;
        return ;
    }

    
    return ;
}


// if empty → return

// print table

// ask index
// if invalid → return

// print full contact
