#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <stdexcept>

AForm *Intern::makeRobotomy(const std::string &target)
{
    return new RobotomyRequestForm(target);
}

AForm *Intern::makePresidential(const std::string &target)
{
    return new PresidentialPardonForm(target);
}

AForm *Intern::makeShruberry(const std::string &target)
{
    return new ShrubberyCreationForm(target);
}

Intern::Intern()
{
}

Intern &Intern::operator=(const Intern &other)
{
    (void)other;
    return (*this);
}

Intern::Intern(const Intern &other)
{
    (void)other;
}

Intern::~Intern()
{
}

AForm *Intern::makeForm(const std::string &name, const std::string &target)
{
    std::string formNames[] = {
        "robotomy request",
        "presidential pardon",
        "shrubbery creation"
    };

    AForm* (Intern::*formMakers[])(const std::string& target) = {
    &Intern::makeRobotomy,
    &Intern::makePresidential,
    &Intern::makeShruberry
    };

    for (size_t i = 0; i < 3; i++)
    {
        if(name == formNames[i])
        {
            std::cout << "Intern Creates " << name << std::endl;
            return (this->*formMakers[i])(target);
        }
    }
    throw std::runtime_error("Intern couldn't find the form named: " + name);
}
