/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuocak <yuocak@student.42kocaeli.com.tr>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-02-07 12:47:43 by yuocak            #+#    #+#             */
/*   Updated: 2026-02-07 12:47:43 by yuocak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

/* ************************************************************************** */
/*                         Orthodox Canonical Form                            */
/* ************************************************************************** */

Fixed::Fixed(): _value(0)
{

}

Fixed::Fixed(const Fixed &other)
{
	*this = other;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	
	if (this != &other)
		this->_value =  other._value;
	return(*this);
}

Fixed::~Fixed()
{

}

/* ************************************************************************** */
/*                            Parameterized Constructors                      */
/* ************************************************************************** */

Fixed::Fixed(int a)
{
	this->_value = a << this->_bit;
}

Fixed::Fixed(float a)
{
	this->_value = static_cast<int>(roundf(a *(1 << _bit)));
}

/* ************************************************************************** */
/*                            Member Functions                                */
/* ************************************************************************** */

int Fixed::getRawBits(void) const
{
	return _value;
}

int Fixed::getValue(void) const
{
	return _value;
}

void Fixed::setRawBits(int const raw)
{
	 this->_value = raw;
}

float Fixed::toFloat( void ) const
{
	return (static_cast<float>(_value)/(1 << _bit));
}

int Fixed::toInt( void ) const
{
	return(_value >> _bit);
}

/* ************************************************************************** */
/*                            Operator Overloads                              */
/* ************************************************************************** */

std::ostream& operator << (std::ostream &out, const Fixed& other)
{
	out << other.toFloat();
	return (out);
}

bool Fixed::operator>(const Fixed& rhs) const
{
    return(this->_value > rhs.getRawBits());
}

bool Fixed::operator<(const Fixed& rhs) const
{
    return(this->_value < rhs.getRawBits());
}

bool Fixed::operator>=(const Fixed& rhs) const
{
    return(this->_value >= rhs.getRawBits());
}

bool Fixed::operator<=(const Fixed& rhs) const
{
    return(this->_value <= rhs.getRawBits());
}

bool Fixed::operator==(const Fixed& rhs) const
{
    return(this->_value == rhs.getRawBits());
}

bool Fixed::operator!=(const Fixed& rhs) const
{
    return(this->_value != rhs.getRawBits());
}

Fixed Fixed::operator+(const Fixed& rhs) const
{
    return(Fixed(this->toFloat() + rhs.toFloat()));
}

Fixed Fixed::operator-(const Fixed& rhs) const
{
    return(Fixed(this->toFloat() - rhs.toFloat()));
}

Fixed Fixed::operator*(const Fixed& rhs) const
{
    return(Fixed(this->toFloat() * rhs.toFloat()));
}

Fixed Fixed::operator/(const Fixed& rhs) const
{
    return(Fixed(this->toFloat() / rhs.toFloat()));
}

Fixed& Fixed::operator++()
{
    this->_value++;
    return *this;
}

Fixed& Fixed::operator--()
{
    this->_value--;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed tmp(*this);

    this->_value++;
    return(tmp);
}

Fixed Fixed::operator--(int)
{
    Fixed tmp(*this);
    
    this->_value--;
    return(tmp);
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    if(a < b)
        return(a);
    else
        return(b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
    if(a < b)
        return(a);
    else
        return(b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    if(a > b)
        return(a);
    else
        return(b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    if(a > b)
        return(a);
    else
        return(b);
}