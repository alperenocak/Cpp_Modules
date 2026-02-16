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
    std::cout << "\n--- 1. BÖLÜM: Yaratılış (Constructors) ---" << std::endl;
    ClapTrap robotA("Alfa");
    ClapTrap robotB("Beta");

    std::cout << "\n--- 2. BÖLÜM: Temel Savaş Testi ---" << std::endl;
    robotA.attack("Hedef Tahtası"); // Enerji düşmeli
    robotA.takeDamage(5);           // Can düşmeli
    robotA.beRepaired(3);           // Can artmalı, enerji düşmeli

    std::cout << "\n--- 3. BÖLÜM: Enerji Tüketimi Testi ---" << std::endl;
    // Enerjiyi bitirelim (zaten 2 harcadık, 8 kaldı)
    for (int i = 0; i < 9; i++)
        robotA.attack("Zombi");

    std::cout << "\n--- 4. BÖLÜM: Ölüm Testi (Hit Points) ---" << std::endl;
    robotB.takeDamage(100); // Aşırı hasar
    robotB.attack("Hayalet"); // Ölü robot saldıramamalı
    robotB.beRepaired(50);    // Ölü robot tamir olamamalı

    std::cout << "\n--- 5. BÖLÜM: OCF Testleri (Kopyalama) ---" << std::endl;
    ClapTrap robotC(robotA); // Copy Constructor
    ClapTrap robotD("Delta");
    robotD = robotA;         // Copy Assignment Operator

    std::cout << "\n--- 6. BÖLÜM: Yıkım (Destructors) ---" << std::endl;
    return (0);
}