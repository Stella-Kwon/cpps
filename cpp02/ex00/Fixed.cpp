/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skwon2 <skwon2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:05:57 by skwon2            #+#    #+#             */
/*   Updated: 2024/12/19 11:30:35 by skwon2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Initialization (e.g., Fixed a = b;) uses the copy constructor.
// Assignment (e.g., a = b;) uses the copy assignment operator.

// if there is no defined copy assignemnet operator (What If You Don’t Overload operator=?)
// If you don't explicitly define your own operator= in your Fixed class,
// C++ will generate a default copy assignment operator for you. The default operator:

// Performs a member-wise copy, copying each member variable from the source object to the target object.
// Does not handle special cases like dynamic memory or resource management.


// Member functions are shared among all objects and are stored once in memory (text/code segment).
// Static members are shared among all objects and are stored in a single memory location (data segment).
// The this pointer allows member functions to know which object they are working with. but not with static members as they do not requires object

Fixed::Fixed(): _fixedPoint(0){
    std::cout << "Default constructor called" << std::endl;    
}

Fixed::~Fixed(){
    std::cout << "Destructor called" << std::endl;    
}

// Fixed& Fixed::operator=(const Fixed& oldFixed) : _fixedPoint(oldFixed._fixedPoin){};
// initializer list is not allowed within copy assignment operator.
// because it does not create an instance anymore.
Fixed& Fixed::operator=(const Fixed& oldFixed){    
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &oldFixed) // as you cannot set the value while c
    {
        //because of the subject instructs us to call the getrawbit() while in this function.
        _fixedPoint = oldFixed.getRawBits();

        // 2.
        // _fixedPoint = oldFixed._fixedPoint;
    }
    return *this;
    //return this will not allowed as this is a pointer to an object.
    //*this : dereferencing this to get the current object itself.
    // Fixed a, b, c;
    // a = b = c; // Error
    // then when we 
}

Fixed::Fixed(const Fixed& oldFixed) : _fixedPoint(oldFixed._fixedPoint) {
    std::cout << "Copy constructor called" << std::endl;
    
    // The copy constructor is called to create a new object (this).
    // The 'this' pointer refers to the current object being created (new object).
    // 'oldFixed' is the source object from which the data will be copied.
    
    *this = oldFixed; 
    // This calls the copy assignment operator, 
    //which copies the data from oldFixed to the current object (the one being constructed).
    // so you need to declare the operator=()function as well in the object.
    // *this refers to the object being constructed. =>  it's a reference to the object itself
    //It is NOT the address of oldFixed.
    //think as it gets inside of the contents of the class
    // In C++, this is automatically a pointer to the object, 
    // and dereferencing it with *this gives you the object itself, not the address. 
    // This is similar to accessing a member of a struct or class via a pointer but done implicitly by the language.
    // The copy assignment operator will copy the actual data (like _fixedPoint) from oldFixed to the new object, not the address.
}

int Fixed::getRawBits( void ) const{
    std::cout << "getRawBits member function called" << std::endl;
    return _fixedPoint;
}

void Fixed::setRawBits( int const raw ){
    std::cout << "setRawBits member function called" << std::endl;
    _fixedPoint = raw;
}


