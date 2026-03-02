/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuocak <yuocak@student.42kocaeli.com.tr>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-03-02 14:36:26 by yuocak            #+#    #+#             */
/*   Updated: 2026-03-02 14:36:26 by yuocak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP
#include <iostream>
class Bureaucrat;

class AForm
{
private:
    bool  _sign;
    const std::string _name;
    const int   _signgrade;
    const int _execgrade;
public:
    AForm();
    AForm& operator=(const AForm& other);
    AForm(const AForm& other);
    virtual ~AForm();
    AForm(const std::string name, const int signgrade, const int execgrade);

    class GradeTooHighException : public std::exception{
        public:
            virtual const char* what() const throw();
    };
    class GradeTooLowException : public std::exception{
        public:
            virtual const char* what() const throw();
    };
    class NotSignedException : public std::exception{
        public:
            virtual const char* what() const throw();
    };
    bool getSign() const;
    int getSignGrade() const;
    int getExecGrade() const;
    std::string getName() const;
    void beSigned(const Bureaucrat& b);
    virtual void execute(Bureaucrat const & executor) const = 0;
};
std::ostream& operator<<(std::ostream& out, const AForm& b);
#endif