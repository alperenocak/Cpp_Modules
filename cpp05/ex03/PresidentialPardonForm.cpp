#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
PresidentialPardonForm::PresidentialPardonForm():AForm("PresidentialPardonForm", 25, 5), _target("Default") {}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
    if (this != &other)
    this->_target = other._target;
    return(*this);
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other), _target(other._target) {}
PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("PresidentialPardonForm", 25, 5), _target(target) {}

PresidentialPardonForm::~PresidentialPardonForm(){}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    if (!this->getSign())
		throw AForm::NotSignedException();
	if(executor.getGrade() > this->getExecGrade())
		throw AForm::GradeTooLowException();
    std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl; 
}