#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
int main()
{
    try
    {
 
        Bureaucrat a("alperen", 1);
        ShrubberyCreationForm form("home");
        RobotomyRequestForm ak("robotimized");
        PresidentialPardonForm bak("irfo");
        a.signForm(form);
        form.execute(a);
        a.signForm(ak); 
        ak.execute(a);
        a.signForm(bak);
        bak.execute(a);
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error caught: " << e.what() << '\n';
    }
    
    return 0;
}