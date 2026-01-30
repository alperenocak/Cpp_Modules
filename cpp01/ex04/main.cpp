/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuocak <yuocak@student.42kocaeli.com.tr>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-01-28 07:23:26 by yuocak            #+#    #+#             */
/*   Updated: 2026-01-28 07:23:26 by yuocak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include "replacer.hpp"

int main()
{
    std::string filename;
    std::string s1;
    std::string s2;

    std::cout << BOLD << CYAN << "╔════════════════════════════════════════╗" << RESET << std::endl;
    std::cout << BOLD << CYAN << "║         🔄 STRING REPLACER 🔄          ║" << RESET << std::endl;
    std::cout << BOLD << CYAN << "╚════════════════════════════════════════╝" << RESET << std::endl;
    std::cout << std::endl;

    std::cout << YELLOW << "📁 Enter filename: " << RESET;
    if(!std::getline(std::cin, filename) || filename.empty())
    {
        std::cerr << RED <<"\n❌ Error: Filename string cannot be empty!" << RESET << std::endl;
        return 1;
    }

    std::cout << RED << "🔍 Enter string to find: " << RESET;
    if(!std::getline(std::cin, s1) || s1.empty())
    {
        std::cerr << RED << "\n❌ Error: Search string cannot be empty!" << RESET << std::endl;
        return 1;
    }

    std::cout << GREEN << "✏️  Enter replacement string: " << RESET;
    if(!std::getline(std::cin, s2) || s2.empty())
    {
        std::cerr << RED << "\n❌ Error: Replacement string cannot be empty!" << RESET << std::endl;
        return 1;
    }

    std::cout << std::endl;
    std::cout << MAGENTA << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << RESET << std::endl;
    std::cout << BLUE << "📄 File: " << RESET << filename << std::endl;
    std::cout << BLUE << "🔎 Find: " << RESET << "\"" << s1 << "\"" << std::endl;
    std::cout << BLUE << "📝 Replace: " << RESET << "\"" << s2 << "\"" << std::endl;
    std::cout << MAGENTA << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << RESET << std::endl;
    std::cout << std::endl;

    if(!replacer(s1, s2, filename))
        return 0;

    std::cout << BOLD << GREEN << "✅ Done! Check " << filename << ".replace" << RESET << std::endl;

    return 0;
}