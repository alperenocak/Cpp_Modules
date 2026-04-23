#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>

template<typename T>
class Array
{
private:
    unsigned int _size;
    T* _data;
public:
    Array();
    ~Array();
    Array(unsigned int n);
    Array(const Array& other);
    Array& operator=(const Array& other);

    T& operator[](unsigned int index);
    const T& operator[](unsigned int index) const;
    unsigned int size() const;
};

template<typename T>
Array<T>::Array(): _data(NULL), _size(0){}

template<typename T>
Array<T>::Array(unsigned int n): _data(NULL)
{
    this->_size = n;
    if(n > 0)
    {
        this->_data = new T[n]();
    }
}

template<typename T>
Array<T>::~Array()
{
    if(this->_data)
        delete[] this->_data;
}

template<typename T>
T& Array<T>::operator[](unsigned int index)
{
    if (index >= _size)
        throw std::out_of_range("out of bounds");
    return this->_data[index];
}

template<typename T>
const T& Array<T>::operator[](unsigned int index) const
{
    if (index >= _size)
        throw std::out_of_range("out of bounds");
    return this->_data[index];
}

template<typename T>
Array<T>::Array(const Array& other)
{
    this->_size = other._size;
    if (this->_size > 0)
    {
        this->_data = new T[this->_size];
        for (unsigned int i = 0; i < this->_size; i++)
        {
            this->_data[i] = other._data[i];
        }
    }
    else
        this->_data = NULL;
}

template<typename T> 
Array<T>& Array<T>:: operator=(const Array<T>& other)
{
    if (this != &other)
    {
        if(this->_data)
            delete[] this->_data;

        this->_size = other._size;
        if(this->_size > 0)
        {
            this->_data = new T[this->_size];
            for (unsigned int i = 0; i < this->_size; i++)
                this->_data[i] = other._data[i];
        }
        else
            this->_data = NULL;
    }
    return *this;
}

template<typename T>
unsigned int Array<T>::size() const
{
    return this->_size;
}
                                                                                          
#endif