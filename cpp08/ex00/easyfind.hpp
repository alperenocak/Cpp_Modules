#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <exception>
# include <algorithm>

class NoFound : public std::exception {
public:
    virtual const char* what() const throw();
};

template <typename T>
typename T::iterator easyfind(T &array, int number);

# include "easyfind.tpp"

#endif