/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrongWrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skwon2 <skwon2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:57:21 by skwon2            #+#    #+#             */
/*   Updated: 2025/01/15 11:53:50 by skwon2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal(){
    type = "WrongCat";
    std::cout << "WrongCat " << type << " is created." << std::endl;
}

WrongCat::~WrongCat(){
    std::cout << "WrongCat " << type << " is destructed." << std::endl;
}

WrongCat::WrongCat(const WrongCat& other): WrongAnimal(other){
    
    std::cout << "WrongCat is copied to " << type << "." << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other){
    if (this != &other)
    {
        type = other.type;
        std::cout << "WrongCat copy assignment constructor is called." << std::endl; 
    }
    return (*this);
}

const std::string& WrongCat::getType() const{
    return (type);
}

void WrongCat::makeSound() const{
    std::cout << "Wrongcat MEOW MEOW" << std::endl;
}