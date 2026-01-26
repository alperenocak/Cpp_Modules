/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuocak <yuocak@student.42kocaeli.com.tr>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-01-26 09:15:59 by yuocak            #+#    #+#             */
/*   Updated: 2026-01-26 09:15:59 by yuocak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    Zombie Zombie1("Zombie Mehmet");

    randomChump("Zombie Irfan");
    Zombie1.announce();
    Zombie *ptr = newZombie("Zombie Said");
    ptr->announce();
    delete(ptr);
}