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
    std::cout << "--- Creating ClapTraps ---" << std::endl;
    ClapTrap a("Alfa");
    ClapTrap b("Beta");

    std::cout << "\n--- Basic combat test ---" << std::endl;
    a.attack("Beta");
    a.takeDamage(5);
    a.beRepaired(3);

    std::cout << "\n--- Energy drain test ---" << std::endl;
    for (int i = 0; i < 9; i++)
        b.attack("Target");
    b.attack("Target");

    std::cout << "\n--- Lethal damage test ---" << std::endl;
    a.takeDamage(100);
    a.attack("Beta");
    a.beRepaired(5);

    std::cout << "\n--- Copy tests ---" << std::endl;
    ClapTrap c(b);
    ClapTrap d;
    d = b;

    std::cout << "\n--- Destruction ---" << std::endl;
    return (0);
}