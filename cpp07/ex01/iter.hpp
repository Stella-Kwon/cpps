#pragma once
#include <iostream>


//pointer in pram is value of the address of the type.
//std::string array[] is actually std::string* array => in which pointing to the first element.
//std::string (&array)[3] => giving  reference, specific address of array elements
//T (&array)[N] => reference to specific
#pragma once
#include <cstddef> // for size_t
#include <iostream>
#include <limits>  // for numeric limits

template <typename T, typename F>
void iter(T *array_address, size_t array_length, F func)
{
    if (array_address)
    {
        for (size_t i = 0; i < array_length; ++i)
        {
            func(array_address[i]);
        }
    }
}

template <typename T>
void add(T &a)
{
    if (a == std::numeric_limits<T>::max())
    {
        std::cerr << "Exceeded max value for type T\n";
        return;
    }
    else if (a == std::numeric_limits<T>::min())
    {
        std::cerr << "Exceeded min value for type T\n";
        return;
    }
    a += 1;
}

template<typename T>
void toUpperCase(T &c) {
    if (c >= 'a' && c <= 'z') {
        c -= 32;
    }
}
template <typename T>
void display(const T &value) {
    std::cout << value << " ";
}