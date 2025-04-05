/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skwon2 <skwon2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 14:42:07 by skwon2            #+#    #+#             */
/*   Updated: 2024/12/06 17:22:34 by skwon2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug(void){
    std::cout << "<DEBUG>" << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}
void Harl::info(void){
    std::cout << "<INFO>" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}
void Harl::warning(void){
    std::cout << "<WARNING>" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}
void Harl::error(void){
    std::cout << "<ERROR>" << std::endl;
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}
void Harl::complain( std::string level ){
    
    //the array of function member : methods can be created under these conditions;
    //1. the same return type
    //2. the same parameter type
    //or
    //Use polymorphism to make functions to be have the same interface "Virtual"
    //need to hand over with & as you should know the address of the methods.
    //that is why the array with *
    void (Harl::*complains[4])(void)= {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error
    };
    std::string levels[4]{
        "DEBUG",
        "INFO",
        "WARNING",
        "ERROR"
    };
///////////////////////////////////////////////////////////////////////////
    // int i;
    // for(i = 0; i < 4; i++)
    // {
    //     // std::cout <<"i : " << i << std::endl;
    //     if (level == levels[i]) //(this->*complains[i])() // this itself has address of the object and need to put * in order to grab the value of it
    //     {
    //        // complains[i]();// is not working
    //         //to call member of function pointer, need to use this 
    //         //because this is a function within the object.
    //         (this->*complains[i])(); //can be (*this.*complains[i])(parameter); 
    //         while (++i < 4)
    //             (this->*complains[i])();
    //         return ;
    //     }
    //     else if (level != levels[0] && level != levels[1] && level != levels[2] &&  level != levels[3])
    //     {
    //         std::cout << "Probably complaining about insignificant problems" << std::endl;
    //         return ;    
    //     }
    // }

//////////////////////////////////////////////////////////////////////////// 

//  fall-through behavior
    // switch(level[0]){
    // case 'D':
    //     if (level == levels[0]) // if will not let fall through
    //         (this->*complains[0])();
    // case 'I':
    //     if (level == levels[1])
    //         (this->*complains[1])();
    // case 'W':
    //     if (level == levels[2])
    //         (this->*complains[2])();
    // case 'E':
    //     if (level == levels[3])
    //         (this->*complains[3])();
    // default :
    //     std::cout << "Probably complaining about insignificant problems" << std::endl;
    //     break;
    // }

    switch (level[0]) {
        case 'D':
            (this->*complains[0])();
        case 'I':
            (this->*complains[1])();
        case 'W':
            (this->*complains[2])();
        case 'E':
            (this->*complains[3])();
        default:
            std::cout << "Probably complaining about insignificant problems" << std::endl;
        break;
    }

}