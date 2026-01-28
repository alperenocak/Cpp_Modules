/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuocak <yuocak@student.42kocaeli.com.tr>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-01-27 12:52:25 by yuocak            #+#    #+#             */
/*   Updated: 2026-01-27 12:52:25 by yuocak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon): _name(name), _weapon(weapon)
{ 
}

HumanA::~HumanA()
{
}

void HumanA::attack()
{
    std::cout << this->_name << "attacks with their" << _weapon.getType() << std::endl;
}