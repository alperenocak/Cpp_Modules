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

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define CYAN    "\033[36m"
#define BOLD    "\033[1m"

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
    std::getline(std::cin, input);
    a.complain(input);
}