/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skwon2 <skwon2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:06:18 by skwon2            #+#    #+#             */
/*   Updated: 2024/12/19 10:24:15 by skwon2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

// #include <string.h>
# include <iostream>


class Fixed{
        private:
            int _fixedPoint;
            static const int fractional_bits = 8;
        public:
            Fixed();
            Fixed(const Fixed& oldFixed); // copy constructor
            ~Fixed();
            Fixed& operator=(const Fixed& oldFixed);//copy assignment operator overload.
            int getRawBits( void ) const;
            void setRawBits( int const raw );
          
};

#endif