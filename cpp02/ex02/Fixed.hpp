/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skwon2 <skwon2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:06:18 by skwon2            #+#    #+#             */
/*   Updated: 2024/12/30 18:01:42 by skwon2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <cmath>
# include <iostream>


class Fixed{
        private:
            int _fixedPoint;
            static const int fractional_bits = 8;
        public:
            Fixed();
            Fixed(const int intNum);
            Fixed(const float floatNum);
            Fixed(const Fixed& oldFixed); // copy constructor
            
            ~Fixed();
            Fixed& operator=(const Fixed& newFixed);//copy assignment operator overload.
            //need to return the new one on the old place
            //so which means with '=' will allow the modifiying the current object(*this).
            // so the return value has to be set in reference.

            // but this does not ned Fixed& return.
            // this will give you the new object with changed value.
            Fixed operator*(const Fixed& next);
            Fixed operator-(const Fixed& next);
            Fixed operator+(const Fixed& next);
            Fixed operator/(const Fixed& next);

            // the const at the end!
            // Why the const is Important?
            // In C++, when you declare a function as const at the end of the function signature, 
            // it indicates that the function does not modify the state of the object that it's called on. 
            // This is crucial for two main reasons:

            // Enabling calls on const objects: 
            // If you want your operator to be callable on const objects 
            // (e.g., passing a const Fixed& as a parameter), 
            // you need to declare it as const at the end of the method.

            // Enabling const-correctness: 
            // It ensures that the operator doesn’t modify the object it operates on, 
            // which is expected in comparison operators 
            // because you are comparing the values without altering the objects.
            bool operator>(const Fixed& next) const;
            bool operator<(const Fixed& next) const;
            bool operator>=(const Fixed& next) const;
            bool operator<=(const Fixed& next) const;
            bool operator==(const Fixed& next) const;
            bool operator!=(const Fixed& next) const;

            Fixed& operator--(); 
            //pre-increment function has to be given as a reference return.
            //as it will retreive the object and add/substract 1 value itself
            // and return itself back.
            // so it should be given with the return by reference.                   

            // but with post-increment function has to given as return by value.
            // a++ works on the caculation has to be done first within the function,
            // but returning the previous value of the object
            // in which we need to call copy constructor to copy the object first before the caculation
            // so that we can retrun the value as return by value 
            // which that will be not temporary but new object that will be preserved and 
            // return to the caller and independent from the caller.
            Fixed operator--(int); 
            //you can omit the parameter name in a function declaration or definition if it is unused. 
            //In the case of the post-increment operator overload, the int parameter is a dummy parameter 
            //that distinguishes the post-increment version from the pre-increment version. 
            Fixed& operator++();
            Fixed operator++(int);

            static Fixed& min(Fixed& a, Fixed& b);
            static const Fixed& min(const Fixed& a, const Fixed& b);
            //why having both version without const and const?
            //to make sure that the compiler automatically chooses the appropiate version based on whether the arguments are const or non-const.
            //Returning a const reference ensures that the result remains immutable when working with const object.
            static Fixed& max(Fixed& a, Fixed& b);
            static const Fixed& max(const Fixed& a, const Fixed& b);
            int getRawBits( void ) const;
            void setRawBits( int const raw );
            float toFloat( void ) const;
            int toInt( void ) const;
};

//not related in maniplating  fixed point
// stream insertion related.

std::ostream& operator<<(std::ostream& out, const Fixed& object);//copy assignment operator overload.
#endif