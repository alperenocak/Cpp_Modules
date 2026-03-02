/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuocak <yuocak@student.42kocaeli.com.tr>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-02-27 21:32:46 by yuocak            #+#    #+#             */
/*   Updated: 2026-02-27 21:32:46 by yuocak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
    // Test 1: Successful signing
    try
    {
        Bureaucrat a("Alperen", 1);
        Form f("TaxForm", 50, 25);
        std::cout << a;
        std::cout << f;
        a.signForm(f);
        std::cout << f;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    // Test 2: Grade too low to sign
    try
    {
        Bureaucrat b("Bob", 100);
        Form f2("SecretForm", 10, 5);
        std::cout << b;
        b.signForm(f2);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    // Test 3: Invalid bureaucrat grade
    try
    {
        Bureaucrat c("Invalid", 0);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    // Test 4: Invalid form grade
    try
    {
        Form f3("BadForm", 0, 10);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}