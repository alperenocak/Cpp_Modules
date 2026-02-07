/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuocak <yuocak@student.42kocaeli.com.tr>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-02-02 09:36:19 by yuocak            #+#    #+#             */
/*   Updated: 2026-02-02 09:36:19 by yuocak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
class Fixed
{
private:
    int _value;
    static const int _bit = 8;
public:
    
    Fixed();
    Fixed(int a);
    Fixed(float a);
    Fixed(const Fixed& other);
    Fixed& operator=(const Fixed& other);
    ~Fixed();
    
    int getRawBits( void ) const;
    void setRawBits( int const raw );
    int getValue(void) const;
    float toFloat( void ) const;
    int toInt( void ) const;
    
};
std::ostream& operator << (std::ostream &out, const Fixed& other);

#endif