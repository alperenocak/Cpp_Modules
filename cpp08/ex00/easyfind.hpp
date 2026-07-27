#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <exception>
#include <algorithm>


template<typename T>
typename T::iterator easyfind(T &array, int number)
{
    class NoFound: public std::exception{
    public:
        virtual const char* what() const throw(){
            return "Number not found!";
        }
        
    };
    typedef typename T::iterator arrayIt;
    arrayIt it = std::find(array.begin(), array.end(), number);
    if(it == array.end())
        throw NoFound();
    return it;
    
}
#endif