/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuocak <yuocak@student.42kocaeli.com.tr>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-02-27 23:31:13 by yuocak            #+#    #+#             */
/*   Updated: 2026-02-27 23:31:13 by yuocak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"
Form::Form():_sign(false), _name("Default Form"), _signgrade(150), _execgrade(150){}
Form &Form::operator=(const Form &other)
{
    if(this != &other)
        this->_sign = other._sign;
    return(*this);
}
Form::Form(const Form &other): _sign(other._sign), _name(other._name), _signgrade(other._signgrade), _execgrade(other._execgrade){}
Form::~Form(){}
Form::Form(const std::string name, const int signgrade, const int execgrade): _sign(false), _name(name), _signgrade(signgrade), _execgrade(execgrade)
{
    if(signgrade < 1 || execgrade < 1)
        throw Form::GradeTooHighException();
    else if(signgrade > 150 || execgrade > 150)
        throw Form::GradeTooLowException();
}
bool Form::getSign() const
{
    return this->_sign;
}
std::string Form::getName() const
{
    return this->_name;
}
void Form::beSigned(const Bureaucrat &b)
{
    if (b.getGrade() > this->_signgrade)
        throw Form::GradeTooLowException();
    this->_sign = true;
}
const char *Form::GradeTooHighException::what() const throw()
{
    return "Form grade is too high! (Max is 1)";
}
const char* Form::GradeTooLowException::what() const throw()
{
    return "Form grade is too low! (Min is 150)";
}

