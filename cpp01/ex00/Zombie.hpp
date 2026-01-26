/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuocak <yuocak@student.42kocaeli.com.tr>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-01-26 09:10:55 by yuocak            #+#    #+#             */
/*   Updated: 2026-01-26 09:10:55 by yuocak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie
{
private:
    
    std::string name;

public:

    ~Zombie();
    Zombie(std::string name);

    void announce(void);
};

void randomChump(std::string name);
Zombie *newZombie(std::string name);

#endif