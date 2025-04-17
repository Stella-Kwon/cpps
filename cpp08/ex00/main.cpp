#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>

int main()
{
    std::vector<int> vec = {1, 2, 3, 4, 5};
    std::list<int> list = { 51, 52, 53, 54, 55};
    try {

        // auto will retrieven T::iterator which is similar to pointer type;
        // so you cannot type into cout stream right away; need to dereference the value
        auto vector_it = easyfind(vec, 3);
        std::cout << "Find 3 in vector in : "
                  << std::distance(vec.begin(), vector_it) + 1 << " position "
                  << *vector_it << std::endl;
        
        auto list_it = easyfind(list, 53);
        std::cout << "Finding 20 in list in : "
                  << std::distance(list.begin(), list_it) + 1 << " position "
                  << *list_it << std::endl;
    } 
    catch (const std::exception &e) 
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}