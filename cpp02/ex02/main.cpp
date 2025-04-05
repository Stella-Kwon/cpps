/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skwon2 <skwon2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:05:25 by skwon2            #+#    #+#             */
/*   Updated: 2024/12/30 19:07:09 by skwon2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) {
Fixed a;
Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
// the upper copy constructor does not called from my copy constructor
// Why Does This Happen?
// The goal of copy elision is to make programs more efficient by avoiding unnecessary object copies. 
// Since temporary objects (such as the result of Fixed( 5.05f ) * Fixed( 2 )) will not be used after the statement, 
// there is no need to copy the result into b—the compiler can just directly construct b in the location where it's needed.

// To Summarize:
// Temporary objects in C++ (such as those returned from an expression like Fixed( 5.05f ) * Fixed( 2 )) are 
// usually subject to compiler optimizations like copy elision or RVO/NRVO.
// These optimizations avoid the copy constructor by directly constructing the object where it's needed, skipping the copy.
// The compiler doesn't use your custom copy constructor for temporary objects if it performs copy elision. 
// Instead, it uses internal optimizations to avoid unnecessary copies.
// If you want to force the copy constructor to be called (for example, to test it), 
// you can disable these optimizations using compiler flags 
// or rearrange the code to avoid temporary objects being directly used in the initialization.

//flag :   -fno-elide-constructors
// or give  avoid temporary objects :  make an instances and use a proper exist object into the copy constructor.
// Fixed temp = Fixed( 5.05f ) * Fixed( 2 ); 
// Fixed const b(temp);

std::cout << a/1 << std::endl;
std::cout << a << std::endl;
std::cout << ++a << std::endl;
std::cout << a << std::endl;
std::cout << a++ << std::endl;
std::cout << a << std::endl;
std::cout << b << std::endl;
std::cout << Fixed::max( a, b ) << std::endl;
std::cout << Fixed::min( a, b ) << std::endl;
return 0;
}