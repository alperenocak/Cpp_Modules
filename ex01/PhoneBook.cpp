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
#include <cstdlib>

// ANSI Renk Kodları
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define BOLD    "\033[1m"

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

bool PhoneBook::addContact()
{
    std::string input;
    
    std::cout << std::endl << GREEN << "┌─── ADD NEW CONTACT ───┐" << RESET << std::endl;
    std::cout << GREEN << "│" << RESET << CYAN << " First Name    : " << RESET;
    if(!std::getline(std::cin, input))
        return false;
    if (input.empty())
    {
        std::cout << RED << "⚠ Input must not be empty ⚠"<< RESET<<std::endl;
        return true;
    }
    _persons[_index].setFirst(input);

    std::cout << GREEN << "│" << RESET << CYAN << " Last Name     : " << RESET;
    if(!std::getline(std::cin, input))
        return false;
    if (input.empty())
    {
        std::cout << RED << "⚠ Input must not be empty ⚠"<< RESET<<std::endl;
        return true;
    }
    _persons[_index].setLast(input);

    std::cout << GREEN << "│" << RESET << CYAN << " Nickname      : " << RESET;
    if(!std::getline(std::cin, input))
        return false;
    if (input.empty())
    {
        std::cout << RED << "⚠ Input must not be empty ⚠"<< RESET<<std::endl;
        return true;
    }
    _persons[_index].setNick(input);

    
    std::cout << GREEN << "│" << RESET << CYAN << " Phone Number  : " << RESET;
    if(!std::getline(std::cin, input))
        return false;
    if (input.empty())
    {
        std::cout << RED << "⚠ Input must not be empty ⚠"<< RESET<<std::endl;
        return true;
    }
    _persons[_index].setPhone(input);

    std::cout << GREEN << "│" << RESET << CYAN << " Dark Secret   : " << RESET;
    if (!std::getline(std::cin, input))
        return false;
    if (input.empty())
    {
        std::cout << RED << "⚠ Input must not be empty ⚠"<< RESET<<std::endl;
        return true;
    }
    _persons[_index].setSecret(input);

    std::cout << GREEN << "└── ✓ Contact Added! ───┘" << RESET << std::endl;

    if (_count < 8)
        _count++;
    _index++;
    if(_index == 8)
        _index = 0;
    return true;
}

bool invalid_input(std::string input, int count)
{
    if (input.empty())
        return true;
    for (size_t i = 0; i < input.length(); i++)
    {
        if (input[i] < '0' || input[i] > '9')
            return true;
    }
    int index = std::atoi(input.c_str());
    if (index < 0 || index >= count)
        return true;
    return false;
}


bool PhoneBook::searchContact() const
{
    if (_count == 0)
    {
        std::cout << RED << "⚠  PhoneBook is empty!" << RESET << std::endl;
        return true;
    }
    
    std::cout << std::endl << YELLOW << "┌──────────────────────────────────────────────┐" << RESET << std::endl;
    std::cout << YELLOW << "│" << BOLD << "     INDEX" << RESET << YELLOW << "|" << BOLD << "     FIRST" << RESET << YELLOW << "|" << BOLD << "      LAST" << RESET << YELLOW << "|" << BOLD << "      NICK" << RESET << YELLOW << "│" << RESET << std::endl;
    std::cout << YELLOW << "├──────────────────────────────────────────────┤" << RESET << std::endl;
    for (int i = 0; i < _count; i++)
    {
        std::cout << YELLOW << "│" << RESET
        << std::setw(10) << i 
        << YELLOW << "|" << RESET
        << std::setw(10) << trim_string(_persons[i].getFirst())
        << YELLOW << "|" << RESET
        << std::setw(10) << trim_string(_persons[i].getLast())
        << YELLOW << "|" << RESET
        << std::setw(10) << trim_string(_persons[i].getNick())
        << YELLOW << "│" << RESET << std::endl;
    }
    std::cout << YELLOW << "└──────────────────────────────────────────────┘" << RESET << std::endl;

    /*----------------------SEARCH INDEX-------------------------*/

    std::string input;
    std::cout << std::endl << BOLD << BLUE << ">> " << RESET << "Enter index to view details: ";
    if (!getline(std::cin, input))
        return false;
    if (invalid_input(input, _count))
    {
        std::cout << RED << "⚠  Invalid index! Please enter a number between 0 and " << _count - 1 << "." << RESET << std::endl;
        return true;
    }
    int index = std::atoi(input.c_str());
    std::cout << std::endl << MAGENTA << "┌─── CONTACT DETAILS ───┐" << RESET << std::endl;
    std::cout << MAGENTA << "│" << RESET << CYAN << " First Name    : " << RESET << _persons[index].getFirst() << std::endl;
    std::cout << MAGENTA << "│" << RESET << CYAN << " Last Name     : " << RESET << _persons[index].getLast() << std::endl;
    std::cout << MAGENTA << "│" << RESET << CYAN << " Nickname      : " << RESET << _persons[index].getNick() << std::endl;
    std::cout << MAGENTA << "│" << RESET << CYAN << " Phone Number  : " << RESET << _persons[index].getPhone() << std::endl;
    std::cout << MAGENTA << "│" << RESET << CYAN << " Dark Secret   : " << RESET << _persons[index].getSecret() << std::endl;
    std::cout << MAGENTA << "└───────────────────────┘" << RESET << std::endl;
    return true;
}
