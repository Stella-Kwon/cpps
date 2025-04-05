/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skwon2 <skwon2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:05:57 by skwon2            #+#    #+#             */
/*   Updated: 2024/12/30 19:06:32 by skwon2           ###   ########.fr       */
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

// Fixed& Fixed::operator=(const Fixed& oldFixed) : _fixedPoint(oldFixed._fixedPoin){};
// initializer list is not allowed within copy assignment operator.
// because it does not create an instance anymore.
Fixed& Fixed::operator=(const Fixed& oldFixed){    
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &oldFixed) // you dont set the value on the same thing.
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
    
    //*this = oldFixed; => here it does not need because with initializing list it already copied values that is needed.
    // this will only cause the double copy operation.
    // it is good to just give values directrly right away while compiling, so that it does not have to assigned initial values and then assigned with copy assignment operator.
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
    // std::cout << "getRawBits member function called" << std::endl;
    return _fixedPoint;
}

void Fixed::setRawBits( int const raw ){
    std::cout << "setRawBits member function called" << std::endl;
    _fixedPoint = raw;
}



float Fixed::toFloat( void ) const{
    return static_cast<float>(_fixedPoint) / (1 << fractional_bits);
}
int Fixed::toInt( void ) const{
    return _fixedPoint >> fractional_bits;
}

std::ostream& operator<<(std::ostream& out, const Fixed& object){
    out << object.toFloat();
    return (out);
}

Fixed Fixed::operator*(const Fixed& next){
    Fixed res;
    res._fixedPoint = (this->_fixedPoint * next._fixedPoint) >> fractional_bits;
    return res;
    // this because those fixedPoint is already * 256 each, so after once multiplying fP * fP should divide / 256 again
    //which is >> fractional_bits.
}
Fixed Fixed::operator-(const Fixed& next){
    Fixed res;
    res._fixedPoint = this->_fixedPoint - next._fixedPoint;
    return res; 
}
Fixed Fixed::operator+(const Fixed& next){
    Fixed res;
    res._fixedPoint = this->_fixedPoint - next._fixedPoint;
    return res; 
}
Fixed Fixed::operator/(const Fixed& next){
    Fixed res;
    res._fixedPoint = (this->_fixedPoint << fractional_bits) / next._fixedPoint;
    //because divide fixedPoint will be the same as dividing normal number(or float),
    // so in order to make the value to fixedPoint again need to *256 again  by giving <<fractional_bits.
    return res;  
    // The res object is local to the function. When the function ends, res is destroyed.
    // To give the caller access to the value of res, the compiler must create a copy (or move, if move semantics are implemented).

    // The copy constructor is called to copy the value of res into the temporary object created for the return value.
    // This temporary object is then used in the caller's context.
}

bool Fixed::operator>(const Fixed& next) const {
   return (this->_fixedPoint > next._fixedPoint);
}
bool Fixed::operator<(const Fixed& next) const{
    return (this->_fixedPoint < next._fixedPoint);
}
bool Fixed::operator>=(const Fixed& next) const{
    return (this->_fixedPoint >= next._fixedPoint);
}
bool Fixed::operator<=(const Fixed& next) const{
    return (this->_fixedPoint <= next._fixedPoint);
}
bool Fixed::operator==(const Fixed& next) const{
    return (this->_fixedPoint == next._fixedPoint);
}
bool Fixed::operator!=(const Fixed& next) const{
   return (this->_fixedPoint != next._fixedPoint);    
}

Fixed& Fixed::operator--(){
    //this is pre-decrement
    this->_fixedPoint--;
    return (*this);
}
Fixed Fixed::operator--(int){
    Fixed res(*this);
    this->_fixedPoint--;
    return res;
} 
Fixed& Fixed::operator++(){
    //this is pre-increment
    //For fixedpoint representation each integer value, 1 represents 1 / 256. = 0.00390625
    this->_fixedPoint++;
    return (*this);
}
Fixed Fixed::operator++(int){
    Fixed res(*this);
    this->_fixedPoint++;
    return res;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
    // (condition) ? expression_if_true : expression_if_false;
    return (a < b) ? a : b; 
}
Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    return (a < b) ? a : b; 
}
Fixed& Fixed::max(Fixed& a, Fixed& b)
{
        return (a > b) ? a : b; 
}
const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
        return (a > b) ? a : b; 
}
