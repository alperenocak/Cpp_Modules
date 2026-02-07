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
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	
	if (this != &other)
		this->setRawBits(other.getRawBits());
	return(*this);
}

Fixed::~Fixed()
{
	std::cout << "Default destructor called" << std::endl;
}

/* ************************************************************************** */
/*                            Parameterized Constructors                      */
/* ************************************************************************** */

Fixed::Fixed(int a)
{
	std::cout << "Int constructor called" << std::endl;
	this->_value = a << this->_bit;
}

Fixed::Fixed(float a)
{
	std::cout << "Float constructor called" << std::endl;
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