#pragma once

#include <stack>
#include <iterator>

template<typename T>
class MutantStack : public std::stack<T>
{
    public: 
        typedef typename std::stack<T>::container_type::iterator iterator;
    
        MutantStack(): std::stack<T>() {}
        MutantStack(const MutantStack& other): std::stack<T>(other) {}
        MutantStack &operator=(const MutantStack& other) {
            if (this != &other)
            {
                std::stack<T>::operator=(other);
            }
            return *this;
        }
        ~MutantStack() {}

        iterator begin() {
            return std::stack<T>::c.begin();
        }
        iterator end() { return std::stack<T>::c.end(); }
};