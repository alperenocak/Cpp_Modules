#ifndef ARRAY_HPP
#define ARRAY_HPP

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

    Array& operator[](const Array& other);
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


#endif