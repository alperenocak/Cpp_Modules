/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuocak <yuocak@student.42kocaeli.com.tr>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-01-09 13:47:56 by yuocak            #+#    #+#             */
/*   Updated: 2026-01-09 13:47:56 by yuocak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() {}

Contact::~Contact() {}

void Contact::setFirst(const std::string value)
{
    _first = value;
}

void Contact::setLast(const std::string value)
{
    _last = value;
}

void Contact::setNick(const std::string value)
{
    _nick = value;
}

void Contact::setPhone(const std::string value)
{
    _phone = value;
}
void Contact::setSecret(const std::string value)
{
    _secret = value;
}

std::string Contact::getFirst() const
{
    return _first;
}

std::string Contact::getLast() const
{
    return _last;
}

std::string Contact::getNick() const
{
    return _nick;
}

std::string Contact::getPhone() const
{
    return _phone;
}

std::string Contact::getSecret() const
{
    return _secret;
}