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
int main()
{
    ClapTrap B;
    ClapTrap A("robot memos");
    A.attack("robot irfo");
    A.takeDamage(3);
    A.beRepaired(3);
}