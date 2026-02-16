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

int main(void)
{
    std::cout << "--- Creating ScavTrap ---" << std::endl;
    ScavTrap guard("Guardian");

    std::cout << "\n--- Combat test ---" << std::endl;
    guard.attack("Intruder");
    guard.takeDamage(30);
    guard.beRepaired(10);

    std::cout << "\n--- Special ability ---" << std::endl;
    guard.guardGate();

    std::cout << "\n--- Copy test ---" << std::endl;
    ScavTrap copy(guard);

    std::cout << "\n--- Destruction ---" << std::endl;
    return (0);
}
