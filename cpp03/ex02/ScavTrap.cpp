
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuocak <yuocak@student.42kocaeli.com.tr>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-02-16 13:03:47 by yuocak            #+#    #+#             */
/*   Updated: 2026-02-16 13:03:47 by yuocak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
ScavTrap::ScavTrap()
{
    this->_name = "Unnamed";
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
    std::cout<<"ScavTrap " << "is born" << std::endl; 
}

ScavTrap::ScavTrap(const ScavTrap &other)
{
    *this = other;
    std::cout << "Copy constructor called!" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
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

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << this->_name << " is dead" << std::endl;
}
ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout<<"ScavTrap " << _name << " is born" << std::endl; 
}

void ScavTrap::attack(const std::string &target)
{
    if (this->_hitPoints > 0 && this->_energyPoints > 0)
    {
        this->_energyPoints--;
        std::cout << "ScavTrap " << _name << " attacks " << target << ", " << "causing " << this->_attackDamage << " points of damage! " << std::endl;
    }
    else
        std::cout << "ScavTrap " << _name << " has no energy or hit points left to attack!" << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap is now in Gate keeper mode." <<std::endl;
}
