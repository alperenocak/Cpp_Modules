/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuocak <yuocak@student.42kocaeli.com.tr>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-01-09 13:48:02 by yuocak            #+#    #+#             */
/*   Updated: 2026-01-09 13:48:02 by yuocak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include "Contact.hpp"

class PhoneBook
{
private:
    Contact _persons[8];
    int     _count;
    int     _index;

    public:
    PhoneBook();
    ~PhoneBook();
    
    bool    addContact();
    bool    searchContact() const;
};

#endif