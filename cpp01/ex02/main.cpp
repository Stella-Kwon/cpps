/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skwon2 <skwon2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 20:33:59 by skwon2            #+#    #+#             */
/*   Updated: 2024/12/20 10:55:13 by skwon2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main()
{
    std::string string = "HI THIS IS BRAIN";
    std::string* stringPTR = &string;
    std::string& stringREF = string;
    
    std::cout << "--------------------------------" << std::endl;
    std::cout << "Address of \"string\" : " << &string << std::endl;
    std::cout << "Address of \"stringPTR\" pointed at: " << stringPTR << std::endl; //address held by stringPTR which in value
    std::cout << "Address of \"stringPTR\" itself : " << &stringPTR << std::endl; //address stringPTR itself
    std::cout << "Address of \"stringREF\" : " << &stringREF << std::endl;
    std::cout << "--------------------------------" << std::endl;
    std::cout << "Value of \"string\" : " << string << std::endl;
    std::cout << "Value of \"stringPTR\" pointed at: " << *stringPTR << std::endl; // value pointed to stringPTR
    std::cout << "Value of \"stringPTR\" itself : " << stringPTR << std::endl; // value pointed to stringPTR
    std::cout << "Value of \"stringREF\" : " << stringREF << std::endl;
    std::cout << "--------------------------------" << std::endl;

    return 0;
}


// int main() {
//     std::string string = "HI THIS IS BRAIN";
//     std::string* stringPTR = &string;
//     std::string& stringREF = string; 

//     std::cout << "Original string: " << string << std::endl;
//     std::cout << "Pointer: " << *stringPTR << std::endl;
//     std::cout << "Reference: " << stringREF << std::endl;

//     // Dynamically allocate a new string
//     std::string* newString = new std::string("DYNAMIC STRING");
//     stringPTR = newString; // Update pointer to point to dynamic string
//     std::cout << "Pointer (updated): " << *stringPTR << std::endl;


//     stringREF = *newString; // Update ref to the newString. 
//     //but once you initialize refer to some place?
//     //References Do Not Change Their Binding    
//     // it will always refers to where you assigned at first

    
//     std::string& stringREF2 = *newString;
    
//     std::cout << "Reference: " << stringREF << std::endl; // this value will be changed to newString value "DYNAMIC STRING"
//     //why?  because reference cannot be rebound after initialization.
//     //so even after newString gets freed, this will look like that it can be still accessible.
//     //because the value of the contents will be replaced in original string "HI THIS IS BRAIN" address.

//     std::cout << "Reference2: " << stringREF2 << std::endl;
    
//     delete newString; // Free dynamic string

//     // Accessing stringPTR now would be undefined behavior! it will segfault.
//     std::cout << "Pointer (updated): " << stringPTR << std::endl; // this will still has itself an address
//     // std::cout << "Pointer (updated): " << *stringPTR << std::endl; // but after being freed, pointing at nowhere will cause segmentation fault.

//     std::cout << "Reference: " << stringREF << std::endl; // Still refers to the stack string
//     //  std::cout << "Reference2: " << stringREF2 << std::endl; // Still refers to the heap newString, so it will be an segfault.
//     std::cout << "Original string: " << string << std::endl; // changed to "DYNAMIC STRING"
//     // std::cout << "New string: " << *newString << std::endl; // cannot access anymore. so it will only prints empty space in endless loop.....
//     return 0;
// }
