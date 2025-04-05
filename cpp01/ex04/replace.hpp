/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skwon2 <skwon2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 14:41:21 by skwon2            #+#    #+#             */
/*   Updated: 2024/12/06 13:28:46 by skwon2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACE_HPP
# define REPLACE_HPP

#include <iostream>
#include <fstream>
#include <string>

class Replace{
    // Simplify the Public Interface
    // Restrict Access to Internal Logic
    // Protect Internal State
    private: 


    //static-member Functions
    //These functions are marked as static 
    //because they do not depend on any instance of the Replace class. 
    //Instead, they are related to the class itself, not to any specific object of the class.
    //This means you can call these functions without creating an instance of the Replace class.
    //which means vice versa, if you dont create an instance of Replace class
    //you cannot access to any other members of the object(class)
    //unless it is static-member functions.
    
        // std::string& replaceStr(const std::string& line, const std::string& s1, const std::string& s2);
        // std::string& 로 반환하게 되면 return되는 값이 함수종료 후 사라지게 되면서 dangling reference가 된다.
        static std::string replaceStr(const std::string& line, const std::string& s1, const std::string& s2);
    public:
        static void replaceInFile(const std::string& filename, const std::string& s1, const std::string& s2);
};

#endif