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
int main()
{
    try
    {
 
        Bureaucrat a("alperen", 1);
        ShrubberyCreationForm form("home");
        a.signForm(form);
        form.execute(a); 
    }
    catch(const std::exception& e)
    {
        std::cerr << "Hata yakalandı: " << e.what() << '\n';
    }
    
    return 0;
}