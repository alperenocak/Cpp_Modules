/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuocak <yuocak@student.42kocaeli.com.tr>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-01-27 12:26:42 by yuocak            #+#    #+#             */
/*   Updated: 2026-01-27 12:26:42 by yuocak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"


int main()
{
{
    Weapon club = ("crude spiked club");
    HumanA bob("Bob", club);
    bob.attack();
    club.setType("AK-47");
    bob.attack();
}
{
    Weapon club("baretta");
    HumanB jim("Jim");
    jim.setWeapon(club);
    jim.attack();
    club.setType("Magnum");
    jim.attack();
}
    return 0;
}
