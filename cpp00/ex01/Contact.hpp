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

#ifndef CONTACT_HPP 
#define CONTACT_HPP

#include <string>

class Contact
{
private:
    std::string _first;
    std::string _last;
    std::string _nick;
    std::string _phone;
    std::string _secret;
public:
    void setFirst(const std::string value);
    void setLast(const std::string value);
    void setNick(const std::string value);
    void setPhone(const std::string value);
    void setSecret(const std::string value);
    
    std::string getFirst(void) const;
    std::string getLast(void) const;
    std::string getNick(void) const;
    std::string getPhone(void) const;
    std::string getSecret(void) const;
    
    Contact();
    ~Contact();
};

#endif