#ifndef INTERN_HPP
#define INTERN_HPP
#include "AForm.hpp"

class Intern
{
private:
    AForm *makeRobotomy(const std::string& target);
    AForm *makePresidential(const std::string& target);
    AForm *makeShruberry(const std::string& target);

public:
    Intern();
    Intern& operator=(const Intern& other);
    Intern(const Intern& other);
    ~Intern();

    AForm* makeForm(const std::string& name, const std::string& target);
};

#endif