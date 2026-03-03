#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
    try
    {
        Intern a;
        AForm* b = a.makeForm("robotomy request", "Bender");
        Bureaucrat c("Irfo", 1);
        c.signForm(*b);
        c.executeForm(*b);
        delete b;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error caught: " << e.what() << '\n';
    }

    try
    {
        Intern a;
        AForm* b = a.makeForm("shrubbery creation", "garden");
        Bureaucrat c("Irfo", 1);
        c.signForm(*b);
        c.executeForm(*b);
        delete b;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error caught: " << e.what() << '\n';
    }

    try
    {
        Intern a;
        AForm* b = a.makeForm("presidential pardon", "Arthur");
        Bureaucrat c("Irfo", 1);
        c.signForm(*b);
        c.executeForm(*b);
        delete b;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error caught: " << e.what() << '\n';
    }

    try
    {
        Intern a;
        AForm* b = a.makeForm("invalid form", "nobody");
        delete b;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error caught: " << e.what() << '\n';
    }
    
    return 0;
}