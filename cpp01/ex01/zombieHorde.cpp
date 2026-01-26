/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuocak <yuocak@student.42kocaeli.com.tr>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-01-26 11:37:30 by yuocak            #+#    #+#             */
/*   Updated: 2026-01-26 11:37:30 by yuocak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
    Zombie *z = new Zombie[N];
    for (int i = 0; i < N; i++)
    {
        z[i].setName(name);
        z[i].announce();
    }
    return(z);
}