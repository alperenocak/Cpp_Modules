/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuocak <yuocak@student.42kocaeli.com.tr>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-01-27 10:14:13 by yuocak            #+#    #+#             */
/*   Updated: 2026-01-27 10:14:13 by yuocak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon
{
private:
    std::string _type;
public:

    Weapon(std::string type);
    ~Weapon();
    const   std::string& getType() const;
    void    setType(std::string type);
};


#endif