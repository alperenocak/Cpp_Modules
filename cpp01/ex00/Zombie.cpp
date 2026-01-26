/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuocak <yuocak@student.42kocaeli.com.tr>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-01-26 09:12:46 by yuocak            #+#    #+#             */
/*   Updated: 2026-01-26 09:12:46 by yuocak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
    this->name = name;
}

Zombie::~Zombie()
{
    std::cout << this->name << ": is dead really..." << std::endl;
}

void Zombie::announce(void)
{
    std::cout<< this->name << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
}