#ifndef ARRAY_HPP
#define ARRAY_HPP

template<typename T>
class Array
{
private:
    T* _data;
    unsigned int _size;
public:
    Array();
    Array(const Array &other);            // Copy Constructor
    Array &operator=(const Array &other); // Assignment Operator
    ~Array();

    Array(unsigned int n);
};

template<typename T>
Array<T>::Array()
{
    this->_data = NULL;
    this->_size = 0;
}
template<typename T>
Array<T>::~Array()
{
    if(this->_data)
        delete[] this->_data;
}
template<typename T>
Array<T>::Array(unsigned int n)
{
    this->_size = n;
    this->_data = new T[n]();
}

#endif