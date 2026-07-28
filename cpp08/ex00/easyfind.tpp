#ifndef EASYFIND_TPP
#define EASYFIND_TPP

#include "easyfind.hpp"

const char* NoFound::what() const throw() {
    return "Number not found!";
}

template <typename T>
typename T::iterator easyfind(T &array, int number) {
    typedef typename T::iterator arrayIt;
    arrayIt it = std::find(array.begin(), array.end(), number);
    if (it == array.end())
        throw NoFound();
    return it;
}

#endif
