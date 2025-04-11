#include "iter.hpp"
#include <iostream>
#include <vector>
#include <cstdlib> 
#include <string>

int main() {
    // Test 1: Integer array
    int intArray[] = {1, 2, 3, 4, 5};
    size_t intSize = sizeof(intArray) / sizeof(intArray[0]);

    std::cout << "Original integer array: ";
    ::iter(intArray, intSize, display<int>);
    std::cout << "\nAfter adding each value: ";
    ::iter(intArray, intSize, add<int>);
    ::iter(intArray, intSize, display<int>);
    std::cout << "\n";

    // Test 2: Float array
    float floatArray[] = {1.1f, 2.2f, 3.3f};
    size_t floatSize = sizeof(floatArray) / sizeof(floatArray[0]);

    std::cout << "\nOriginal float array: ";
    ::iter(floatArray, floatSize, display<float>);
    std::cout << "\nAfter adding each value: ";
    ::iter(floatArray, floatSize, add<float>);
    ::iter(floatArray, floatSize, display<float>);
    std::cout << "\n";

    // Test 3: Character array
    char charArray[] = {'a', 'b', 'c', 'd', 'e'};
    size_t charSize = sizeof(charArray) / sizeof(charArray[0]);

    std::cout << "\nOriginal character array: ";
    ::iter(charArray, charSize, display<char>);
    std::cout << "\nAfter converting to uppercase: ";
    ::iter(charArray, charSize, toUpperCase<char>);
    ::iter(charArray, charSize, display<char>);
    std::cout << "\n";

    // Test 4: String array
    std::string stringArray[] = {"hello", "world", "iter"};
    size_t stringSize = sizeof(stringArray) / sizeof(stringArray[0]);

    std::cout << "\nOriginal string array: ";
    ::iter(stringArray, stringSize, display<std::string>);
    std::cout << "\n";

    return 0;
}


// class Awesome
// {
//   public:
//     Awesome( void ) : _n( 42 ) { return; }
//     int get( void ) const { return this->_n; }
//   private:
//     int _n;
// };

// std::ostream & operator<<( std::ostream & o, Awesome const & rhs )
// {
//   o << rhs.get();
//   return o;
// }

// template< typename T >
// void print( T& x )
// {
//   std::cout << x << std::endl;
//   return;
// }

// int main() {
//   int tab[] = { 0, 1, 2, 3, 4 };
//   Awesome tab2[5];

//   iter( tab, 5, print<const int> );
//   iter( tab2, 5, print<Awesome> );

//   return 0;
// }