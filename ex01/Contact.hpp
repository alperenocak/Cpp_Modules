/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuocak <yuocak@student.42kocaeli.com.tr>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-01-09 13:47:59 by yuocak            #+#    #+#             */
/*   Updated: 2026-01-09 13:47:59 by yuocak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once 
#include <string>
class Contact
{
private:

    std::string person[5];

public:
    Contact();
    std::string getPerson(int i);
    ~Contact();
};

Contact::Contact()
{

}

Contact::~Contact()
{

}
