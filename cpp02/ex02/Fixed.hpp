/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuocak <yuocak@student.42kocaeli.com.tr>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-02-07 12:31:17 by yuocak            #+#    #+#             */
/*   Updated: 2026-02-07 12:31:17 by yuocak           ###   ########.fr       */
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
    bool operator>(const Fixed& rhs) const; 
    bool operator<(const Fixed& rhs) const; 
    bool operator>=(const Fixed& rhs) const; 
    bool operator<=(const Fixed& rhs) const; 
    bool operator==(const Fixed& rhs) const; 
    bool operator!=(const Fixed& rhs) const;

    Fixed operator+(const Fixed& rhs) const;
    Fixed operator-(const Fixed& rhs) const;
    Fixed operator*(const Fixed& rhs) const;
    Fixed operator/(const Fixed& rhs) const;

    Fixed& operator++();
    Fixed& operator--();

    Fixed operator++(int);
    Fixed operator--(int);

    static Fixed& min(Fixed& a, Fixed& b);
    static Fixed& max(Fixed& a, Fixed& b);

    static const Fixed& min(const Fixed &a, const Fixed& b);
    static const Fixed& max(const Fixed &a, const Fixed& b);

    ~Fixed();
    
    int getRawBits( void ) const;
    void setRawBits( int const raw );
    int getValue(void) const;
    float toFloat( void ) const;
    int toInt( void ) const;
    
};
std::ostream& operator << (std::ostream &out, const Fixed& other);

#endif