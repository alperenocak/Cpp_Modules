#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
class PresidentialPardonForm: public AForm
{
private:
    std::string _target;
public:
    PresidentialPardonForm();
    PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
    PresidentialPardonForm(const PresidentialPardonForm& other);
    ~PresidentialPardonForm();
    PresidentialPardonForm(const std::string& target);

    virtual void execute(Bureaucrat const & executor) const;
};

#endif