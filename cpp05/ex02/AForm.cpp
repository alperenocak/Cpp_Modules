/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuocak <yuocak@student.42kocaeli.com.tr>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-03-02 14:36:26 by yuocak            #+#    #+#             */
/*   Updated: 2026-03-02 14:36:26 by yuocak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm():_sign(false), _name("Default Form"), _signgrade(150), _execgrade(150){}

AForm &AForm::operator=(const AForm &other)
{
    if(this != &other)
        this->_sign = other._sign;
    return(*this);
}

AForm::AForm(const AForm &other): _sign(other._sign), _name(other._name), _signgrade(other._signgrade), _execgrade(other._execgrade){}

AForm::~AForm(){}

AForm::AForm(const std::string name, const int signgrade, const int execgrade): _sign(false), _name(name), _signgrade(signgrade), _execgrade(execgrade)
{
    if(signgrade < 1 || execgrade < 1)
        throw AForm::GradeTooHighException();
    else if(signgrade > 150 || execgrade > 150)
        throw AForm::GradeTooLowException();
}

bool AForm::getSign() const
{
    return this->_sign;
}

int AForm::getSignGrade() const
{
    return this->_signgrade;
}

int AForm::getExecGrade() const
{
    return this->_execgrade;
}

std::string AForm::getName() const
{
    return this->_name;
}

void AForm::beSigned(const Bureaucrat &b)
{
    if (b.getGrade() > this->_signgrade)
        throw AForm::GradeTooLowException();
    this->_sign = true;
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return "Form grade is too high! (Max is 1)";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "Form grade is too low! (Min is 150)";
}

std::ostream &operator<<(std::ostream &out, const AForm &other)
{
    out << "Form: " << other.getName()
        << ", signed: " << (other.getSign() ? "yes" : "no")
        << ", sign grade: " << other.getSignGrade()
        << ", exec grade: " << other.getExecGrade()
        << std::endl;
    return (out);
}

