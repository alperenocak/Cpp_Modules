#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("Bureaucrat")
{
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    if (this != &other)
    {
        this->_grade = other._grade;
    }
    return(*this);
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
{
    *this = other;
}

Bureaucrat::~Bureaucrat()
{
}

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

unsigned int Bureaucrat::getGrade() const
{
    return this->_grade;
}

void Bureaucrat::incrementGrade()
{
    this->_grade--;
    if (this->_grade <= 0)
        throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::decrementGrade()
{
    this->_grade++;
    if (this->_grade >= 150)
        throw Bureaucrat::GradeTooLowException();
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Bureaucrat grade is too high! (Max is 1)";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Bureaucrat grade is too low! (Min is 150)";

}

