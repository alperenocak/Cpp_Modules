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
#include "AForm.hpp"
#include <iostream>
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
int main()
{
    // Test 1: robotomy request
    try
    {
        Intern a;
        AForm* b = a.makeForm("robotomy request", "Bender");
        if (!b)
            return 1;
        Bureaucrat c("Irfo", 1);
        c.signForm(*b);
        c.executeForm(*b);
        delete b;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Hata yakalandı: " << e.what() << '\n';
    }

    // Test 2: shrubbery creation
    try
    {
        Intern a;
        AForm* b = a.makeForm("shrubbery creation", "garden");
        if (!b)
            return 1;
        Bureaucrat c("Irfo", 1);
        c.signForm(*b);
        c.executeForm(*b);
        delete b;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Hata yakalandı: " << e.what() << '\n';
    }

    // Test 3: presidential pardon
    try
    {
        Intern a;
        AForm* b = a.makeForm("presidential pardon", "Arthur");
        if (!b)
            return 1;
        Bureaucrat c("Irfo", 1);
        c.signForm(*b);
        c.executeForm(*b);
        delete b;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Hata yakalandı: " << e.what() << '\n';
    }

    // Test 4: geçersiz form ismi
    try
    {
        Intern a;
        AForm* b = a.makeForm("invalid form", "nobody");
        if (!b)
            std::cout << "Form bulunamadı, NULL döndü." << std::endl;
        delete b;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Hata yakalandı: " << e.what() << '\n';
    }
    
    return 0;
}