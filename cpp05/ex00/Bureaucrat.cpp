#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("Bureaucrat")
{
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    // TODO: insert return statement here
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
{
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat::Bureaucrat(const std::string &name, unsigned int grade): _name(name), _grade(grade)
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

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Bureaucrat grade is too high! (Max is 1)";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Bureaucrat grade is too low! (Min is 150)";

}

