#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <ctime>
RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequestForm", 72, 45), _target("robotomized"){}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    if(this != &other)
        this->_target = other._target;
    return(*this);
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other):AForm(other), _target(other._target){}

RobotomyRequestForm::~RobotomyRequestForm(){}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target): AForm("RobotomyRequestForm", 72, 45), _target(target){}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    if (!this->getSign())
		throw AForm::NotSignedException();
	if(executor.getGrade() > this->getExecGrade())
		throw AForm::GradeTooLowException();

    std::cout << "Bıııııııııızzzzzzzzzzzzzzzzzttttt"<<std::endl;
    if (time(NULL) % 2 == 0)
        std::cout << this->_target<< " has been robotomized successfully"<<std::endl;
    else
        std::cout << this->_target<< " robotomy failed"<<std::endl;
}
