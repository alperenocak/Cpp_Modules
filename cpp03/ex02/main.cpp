/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuocak <yuocak@student.42kocaeli.com.tr>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-02-13 12:54:57 by yuocak            #+#    #+#             */
/*   Updated: 2026-02-13 12:54:57 by yuocak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{

    ClapTrap clap("Clappy");
    ScavTrap scav("Scavvy");
    FragTrap frag("Fraggy");

    clap.attack("Enemy");
    clap.takeDamage(5);
    clap.beRepaired(3);

    scav.attack("Enemy");
    scav.takeDamage(20);
    scav.beRepaired(10);
    scav.guardGate();

    frag.attack("Enemy");
    frag.takeDamage(40);
    frag.beRepaired(15);
    frag.highFivesGuys();

    
    return (0);
}
