#pragma once

#include <algorithm>
#include <stdexcept>


template <typename T>
//better to &the containter than *. most of the STL algorithm receive container as &

// -> decltype() is trailing return type in which let compiler to know exact type for auto later at the end.
// before we use typename to let compile to know that is is sort of tool type.
auto easyfind(T &container, int element) -> decltype(container.begin()) {
    auto it = find(container.begin(), container.end(), element);
    if (it == container.end()) 
        throw std::runtime_error("Value is not in the container");
    return it;
}