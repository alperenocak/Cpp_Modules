/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuocak <yuocak@student.42kocaeli.com.tr>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-01-29 12:49:48 by yuocak            #+#    #+#             */
/*   Updated: 2026-01-29 12:49:48 by yuocak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

void Harl::debug(void)
{
    std::cout<< "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-" <<
                "ketchup burger. I really do!" << std::endl;
}

void Harl::info(void)
{
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put "<<
                "enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(void)
{
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for" <<
                "years, whereas you started working here just last month." << std::endl;
}

void Harl::error(void)
{
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
    void (Harl::* levels[4]) (void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    std::string array[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    for (size_t i = 0; i < 4; i++)
    {
        if (level == array[i])
        {
            (this->*levels[i])();
        }        
    }
}
