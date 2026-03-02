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
int main()
{
    try
    {
 
        Bureaucrat a("alperen", 11);
        ShrubberyCreationForm form("home");
        RobotomyRequestForm ak("robotimized");
        PresidentialPardonForm bak("irfo");
        a.signForm(form);
        form.execute(a);
        a.signForm(ak); 
        ak.execute(a);
        a.signForm(bak);
        bak.execute(a);
    }
    catch(const std::exception& e)
    {
        std::cerr << "Hata yakalandı: " << e.what() << '\n';
    }
    
    return 0;
}