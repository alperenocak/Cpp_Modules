/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuocak <yuocak@student.42kocaeli.com.tr>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-01-13 11:13:17 by yuocak            #+#    #+#             */
/*   Updated: 2026-01-13 11:13:17 by yuocak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>

// ANSI Renk Kodları
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define BOLD    "\033[1m"

int main()
{
    PhoneBook   phonebook;
    std::string input;
    std::cout << CYAN << "╔══════════════════════════════════╗" << RESET << std::endl;
    std::cout << CYAN << "║" << BOLD << MAGENTA << "     WELCOME TO THE PHONEBOOK     " << RESET << CYAN << "║" << RESET << std::endl;
    std::cout << CYAN << "╠══════════════════════════════════╣" << RESET << std::endl;
    std::cout << CYAN << "║  " << GREEN << "ADD" << RESET << CYAN << "    - Add a new contact      ║" << RESET << std::endl;
    std::cout << CYAN << "║  " << YELLOW << "SEARCH" << RESET << CYAN << " - Search for a contact   ║" << RESET << std::endl;
    std::cout << CYAN << "║  " << RED << "EXIT" << RESET << CYAN << "   - Exit the phonebook     ║" << RESET << std::endl;
    std::cout << CYAN << "╚══════════════════════════════════╝" << RESET << std::endl;
    
    while (1)
    {
        std::cout << std::endl << BOLD << BLUE << ">> " << RESET << "Enter command: ";
        if (!std::getline(std::cin, input))
            break;
        if (input == "ADD")
        {
            if (!phonebook.addContact())
                break;
        }
        else if (input == "SEARCH")
        {
            if (!phonebook.searchContact())
                break;
        }
        else if (input == "EXIT")
            break;
        else if (!input.empty())
            std::cout << RED << "⚠  Invalid Command! Please use ADD, SEARCH or EXIT." << RESET << std::endl;
    }
    std::cout << std::endl << MAGENTA << "Goodbye! 👋" << RESET << std::endl;
    return 0;
}