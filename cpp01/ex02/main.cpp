/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuocak <yuocak@student.42kocaeli.com.tr>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-01-26 13:37:50 by yuocak            #+#    #+#             */
/*   Updated: 2026-01-26 13:37:50 by yuocak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
    std::string str = "HI THIS IS BRAIN";
    std::string str2 = "HI";
    std::string *stringPTR = &str;
    std::string& stringREF = str;
    
    std::cout << str << std::endl;
    std::cout << *stringPTR << std::endl;
    std::cout << stringREF << std::endl;
    
    stringREF = str2;
    std::cout << stringREF << std::endl;
    std::cout << str << std::endl;
}