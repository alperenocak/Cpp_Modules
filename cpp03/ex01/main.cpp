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
    ScavTrap guard("Guardian");

    guard.attack("Enemy");
    guard.takeDamage(30);
    guard.beRepaired(10);


    guard.guardGate();

    return (0);
    
}
