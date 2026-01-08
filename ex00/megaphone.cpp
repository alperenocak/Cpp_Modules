/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuocak <yuocak@student.42kocaeli.com.tr>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-01-07 12:25:13 by yuocak            #+#    #+#             */
/*   Updated: 2026-01-07 12:25:13 by yuocak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int ac, char **av)
{
    if (ac < 2)
        return 0;
    std::string s;
    for (int count = 1; count < ac; count++)
    {
        for (size_t i = 0; av[count][i]; i++)
        {
            s += (unsigned char)std::toupper(av[count][i]);
        }
        if(count != ac - 1)
            s += ' ';
    }
    std::cout<<s<<std::endl;
    return 0;
}
