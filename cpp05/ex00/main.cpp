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
#include <iostream>

int main()
{
    // Test 1: Normal bureaucrat
    try
    {
        Bureaucrat a("Alperen", 75);
        std::cout << a;
        a.incrementGrade();
        std::cout << "After increment: " << a;
        a.decrementGrade();
        std::cout << "After decrement: " << a;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    // Test 2: Grade too high (0)
    try
    {
        Bureaucrat b("TooHigh", 0);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    // Test 3: Grade too low (151)
    try
    {
        Bureaucrat c("TooLow", 151);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    // Test 4: Increment beyond max grade
    try
    {
        Bureaucrat d("Max", 1);
        std::cout << d;
        d.incrementGrade();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    // Test 5: Decrement beyond min grade
    try
    {
        Bureaucrat e("Min", 150);
        std::cout << e;
        e.decrementGrade();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}