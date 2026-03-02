/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuocak <yuocak@student.42kocaeli.com.tr>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-02-23 12:55:39 by yuocak            #+#    #+#             */
/*   Updated: 2026-02-23 12:55:39 by yuocak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <iostream>
class Form;
class Bureaucrat{
private:
    const std::string _name;
    int _grade;
public:
    Bureaucrat();
    Bureaucrat& operator=(const Bureaucrat& other);
    Bureaucrat(const Bureaucrat& other);
    ~Bureaucrat();
    Bureaucrat(const std::string& name, int grade);
    std::string getName() const;
    int getGrade() const;

    void incrementGrade();
    void decrementGrade();
    class GradeTooHighException : public std::exception{
        public:
            virtual const char* what() const throw();
    };
    class GradeTooLowException : public std::exception{
        public:
            virtual const char* what() const throw();
    };

    void signForm(Form& f);
};
std::ostream& operator<<(std::ostream& out, const Bureaucrat& b);

#endif