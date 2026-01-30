/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuocak <yuocak@student.42kocaeli.com.tr>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-01-29 11:23:39 by yuocak            #+#    #+#             */
/*   Updated: 2026-01-29 11:23:39 by yuocak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <string>
#include <istream>



int main()
{
    Harl a;
    std::string input;
    std::cout << BOLD << CYAN;
    std::cout << "==============================" << std::endl;
    std::cout << "        HARL COMPLAINER        " << std::endl;
    std::cout << "==============================" << RESET << std::endl;
    std::cout << std::endl;

    std::cout << BOLD << "Available levels:" << RESET << std::endl;
    std::cout << GREEN  << " - DEBUG"   << RESET << std::endl;
    std::cout << BLUE   << " - INFO"    << RESET << std::endl;
    std::cout << YELLOW << " - WARNING" << RESET << std::endl;
    std::cout << RED    << " - ERROR"   << RESET << std::endl;
    std::cout << std::endl;

    std::cout << BOLD << "Enter level:" << RESET << std::endl;
    std::cout << CYAN << "> " << RESET;
    if (!std::getline(std::cin, input) || input.empty())
    {
        std::cout << RED <<"Please enter the specified commands." << RESET <<std::endl;
        return (1);
    }
    if(input.compare("DEBUG") != 0 && input.compare("ERROR") != 0 && input.compare("INFO")  != 0 && input.compare("WARNING") != 0)
    {
        std::cerr << RED <<"Please enter the specified commands." << RESET <<std::endl;
        return (1);
    }
    a.complain(input);
}
