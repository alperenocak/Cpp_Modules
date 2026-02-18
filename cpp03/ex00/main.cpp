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

#include "ClapTrap.hpp"

int main(void)
{

    ClapTrap a("Alfa");
    ClapTrap b("Beta");

    a.attack("Beta");
    a.takeDamage(5);
    a.beRepaired(3);

    a.takeDamage(100);
    a.attack("Beta");
    a.beRepaired(5);

    return (0);
}