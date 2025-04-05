/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skwon2 <skwon2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:05:57 by skwon2            #+#    #+#             */
/*   Updated: 2024/12/30 11:08:26 by skwon2           ###   ########.fr       */
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

Fixed::Fixed(const int intNum){
    std::cout << "Int number constructor called" << std::endl;
    _fixedPoint = intNum << fractional_bits;// << is * so it will be same as *256 // giving 8 bits for binary space for 256
}

Fixed::Fixed(const float floatNum){
     std::cout << "Float number constructor called" << std::endl;
    // _fixedPoint = roundf(floatNum << fractional_bits); //does not work
    // bitshift is only working on interger value
    // so that the float number << bits would not work
    _fixedPoint = roundf(floatNum * (1 << fractional_bits)); // 1 << 8 = 256
}

Fixed::~Fixed(){
    std::cout << "Destructor called" << std::endl;    
}

// Fixed& Fixed::operator=(const Fixed& newFixed) : _fixedPoint(newFixed._fixedPoin){};
// initializer list is not allowed within copy assignment operator.
// because it does not create an instance anymore.
// so that is why also it need to be return in reference.
// Fixed& has to be with reference because if you return this which is just Fixed
// it is only returning the memory address of the object.
Fixed& Fixed::operator=(const Fixed& newFixed){    
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &newFixed) // you dont set the value on the same thing.
    {
        //because of the subject instructs us to call the getrawbit() while in this function.
        _fixedPoint = newFixed.getRawBits();

        // 2.
        // _fixedPoint = newFixed._fixedPoint;
    }
    return *this;
    //return this will not allowed as this is a pointer to an object.
    //*this : dereferencing this to get the current object itself.
    // return this;
    // Fixed a, b, c;
    // a = b = c; // Error
    // but if we return *this;
    // a = b = c will be equal to c value.
}

//

Fixed::Fixed(const Fixed& oldFixed) : _fixedPoint(oldFixed._fixedPoint) {
    std::cout << "Copy constructor called" << std::endl;
    
    // The copy constructor is called to create a new object (this).
    // The 'this' pointer refers to the current object being created (new object).
    // 'oldFixed' is the source object from which the data will be copied.
    // however the oldFixed should not copied again as it is calling another copy constructor 
    // which will lead stack overflow or infinite loop. 
    // This would lead to infinite recursion because the copy constructor would call itself repeatedly to create oldFixed
    // for the efficient memory management we should give the parameter(oldFixed)as a reference.
    // so that is why below statment can be worked.
    // dereferencing this will be equal to the referenced oldFixed
    // so now it is pointing to the contents of the data respectively.
    
    // Why const Fixed& is Used:
    // Const Reference: The const Fixed& ensures that the assignment operator can accept both lvalues (named objects) and rvalues (temporary objects) without any issues.

    // Lvalues: Can be any object that exists and is named (e.g., Fixed a = b;).
    // Rvalues: Are temporary objects or expressions that generate temporary objects (e.g., Fixed a = Fixed(3.14f);).
    
    // Temporary Handling: The const keyword is used C++ extends the lifetime of that temporary object for the duration of the operator's execution.
    // in which allows to receive temporary object accessible until the end of the function's scope.
    
    // Efficiency: Passing by reference (const Fixed&) is more efficient than 
    //passing by value because it avoids making a copy of the object being passed.

    // this is also effecting for anycases like operator overload;
    *this = oldFixed;
}

int Fixed::getRawBits( void ) const{
    // std::cout << "getRawBits member function called" << std::endl;
    return _fixedPoint;
}

void Fixed::setRawBits( int const raw ){
    std::cout << "setRawBits member function called" << std::endl;
    _fixedPoint = raw;
}

float Fixed::toFloat( void ) const{
    return static_cast<float>(_fixedPoint) / (1 << fractional_bits);
    // to caculate right: we need to change in right form
    // in which this static_cast<float>(value)will help us out.
    // giving value 5 will change into 5.0 in this case. 
}
int Fixed::toInt( void ) const{
    return _fixedPoint >> fractional_bits;
}

std::ostream& operator<<(std::ostream& out, const Fixed& object){
    out << object.toFloat();
    return (out);
}