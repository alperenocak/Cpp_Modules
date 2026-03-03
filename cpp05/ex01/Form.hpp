#ifndef FORM_HPP
#define FORM_HPP
#include <iostream>

class Bureaucrat;
class Form
{
private:
    bool  _sign;
    const std::string _name;
    const int   _signgrade;
    const int _execgrade;
public:
    Form();
    Form& operator=(const Form& other);
    Form(const Form& other);
    ~Form();
    Form(const std::string name, const int signgrade, const int execgrade);

    class GradeTooHighException : public std::exception{
        public:
            virtual const char* what() const throw();
    };
    class GradeTooLowException : public std::exception{
        public:
            virtual const char* what() const throw();
    };
    bool getSign() const;
    int getSignGrade() const;
    int getExecGrade() const;
    std::string getName() const;
    void beSigned(const Bureaucrat& b);
};
std::ostream& operator<<(std::ostream& out, const Form& b);

#endif