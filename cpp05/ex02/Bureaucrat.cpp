/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuocak <yuocak@student.42kocaeli.com.tr>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-02-27 22:30:04 by yuocak            #+#    #+#             */
/*   Updated: 2026-02-27 22:30:04 by yuocak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
Bureaucrat::Bureaucrat(): _name("Default"), _grade(150){}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    if (this != &other)
    {
        this->_grade = other._grade;
    }
    return(*this);
}

Bureaucrat::Bureaucrat(const Bureaucrat &other): _name(other._name), _grade(other._grade){}

Bureaucrat::~Bureaucrat(){}

Bureaucrat::Bureaucrat(const std::string &name, int grade): _name(name)
{
    if(grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    this->_grade = grade;
}

std::string Bureaucrat::getName() const
{
    return this->_name;
}

int Bureaucrat::getGrade() const
{
    return this->_grade;
}

void Bureaucrat::incrementGrade()
{
    if (this->_grade - 1 < 1)
        throw Bureaucrat::GradeTooHighException();
    this->_grade--;
}

void Bureaucrat::decrementGrade()
{
    if (this->_grade + 1 > 150)
        throw Bureaucrat::GradeTooLowException();
    this->_grade++;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Bureaucrat grade is too high! (Max is 1)";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Bureaucrat grade is too low! (Min is 150)";
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat& other)
{
    out << other.getName() << ", bureaucrat grade " << other.getGrade() << "." << std::endl;
    return(out);
}

void Bureaucrat::signForm(AForm &f)
{
    try
    {
        f.beSigned(*this);
        std::cout << getName() << " signed " << f.getName() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << getName() << " couldn't sign " << f.getName() << " because " << e.what() << std::endl;
    }
    
}