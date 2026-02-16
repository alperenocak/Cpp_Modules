/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuocak <yuocak@student.42kocaeli.com.tr>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-02-16 10:59:08 by yuocak            #+#    #+#             */
/*   Updated: 2026-02-16 10:59:08 by yuocak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// ************************************************************************** //
//                       Orthodox Canonical Form                              //
// ************************************************************************** //

ClapTrap::ClapTrap()
{
    this->_name = "Unnamed";
    this->_hitPoints = 10;
    this->_energyPoints = 10;
    this->_attackDamage = 0;
    std::cout<<"ClapTrap " << "is born" << std::endl; 
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
    *this = other;
    std::cout << "Copy constructor called!" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap& other)
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

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << this->_name << " is dead" << std::endl;
}

// ************************************************************************** //
//                            Constructors                                    //
// ************************************************************************** //

ClapTrap::ClapTrap(std::string name): _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout<<"ClapTrap " << _name << " is born" << std::endl; 
}

// ************************************************************************** //
//                           Member Functions                                 //
// ************************************************************************** //

void ClapTrap::attack(const std::string &target)
{
    if (this->_hitPoints > 0 && this->_energyPoints > 0)
    {
        this->_energyPoints--;
        std::cout << "ClapTrap " << _name << " attacks " << target << ", " << "causing " << this->_attackDamage << " points of damage! " << std::endl;
    }
    else
        std::cout << "ClapTrap " << _name << " has no energy or hit points left to attack!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (amount >= this->_hitPoints)
    {
        this->_hitPoints = 0;
        std::cout << "ClapTrap " << _name << " took " << amount << " damage and is now dead!" << std::endl;
    }
    else{
        this->_hitPoints -= amount;
        std::cout << "ClapTrap " << _name << " took " << amount << " damage! Remaining HP: " << this->_hitPoints << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->_energyPoints > 0 && this->_hitPoints > 0)
    {
        this->_hitPoints += amount;
        this->_energyPoints -= 1;
        std::cout << "ClapTrap " << _name << " repaired itself, gaining " << amount << " hit points! Total HP: " << this->_hitPoints << std::endl;
    }
    else
        std::cout << "ClapTrap " << _name << " cannot repair because it has no energy or hit points left!" << std::endl;
}