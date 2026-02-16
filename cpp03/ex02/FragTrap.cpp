/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuocak <yuocak@student.42kocaeli.com.tr>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-02-16 13:21:14 by yuocak            #+#    #+#             */
/*   Updated: 2026-02-16 13:21:14 by yuocak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

// ************************************************************************** //
//                       Orthodox Canonical Form                              //
// ************************************************************************** //

FragTrap::FragTrap()
{
    this->_name = "Unnamed";
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
    std::cout<<"FragTrap " << this->_name << " is born" << std::endl; 
}

FragTrap::FragTrap(const FragTrap &other)
{
    *this = other;
    std::cout << "Copy constructor called!" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
    if(this != &other)
    {
        this->_attackDamage = other._attackDamage;
        this->_name = other._name;
        this->_hitPoints = other._hitPoints;
        this->_energyPoints = other._energyPoints;
    }
    std::cout << "Copy assigment operator called!" << std::endl;

    return(*this);   
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << this->_name << " is dead" << std::endl;
}

// ************************************************************************** //
//                            Constructors                                    //
// ************************************************************************** //

FragTrap::FragTrap(std::string name):ClapTrap(name)
{
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout<<"FragTrap " << _name << " is born" << std::endl; 
}

// ************************************************************************** //
//                           Member Functions                                 //
// ************************************************************************** //


void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap is now in High Five Guys mode."<< std::endl;
}
