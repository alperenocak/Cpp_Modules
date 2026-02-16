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
    std::cout << "--- 1. AŞAMA: ScavTrap Doğuyor ---" << std::endl;
    ScavTrap robot("Guardian");

    std::cout << "\n--- 2. AŞAMA: Özellik Kontrolü ---" << std::endl;
    robot.attack("Intruder"); 
    
    robot.takeDamage(10);
    robot.beRepaired(5);

    std::cout << "\n--- 3. AŞAMA: Özel Yetenek ---" << std::endl;
    robot.guardGate();

    std::cout << "\n--- 4. AŞAMA: Yıkım (Destruction) ---" << std::endl;
    return (0);
}
