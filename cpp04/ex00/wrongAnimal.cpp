/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skwon2 <skwon2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:57:21 by skwon2            #+#    #+#             */
/*   Updated: 2025/01/15 11:57:47 by skwon2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wrongAnimal.hpp"

WrongAnimal::WrongAnimal(): type("Empty"){
    std::cout << "WrongAnimal " << type << " is created." << std::endl;
}

WrongAnimal::~WrongAnimal(){
    std::cout << "WrongAnimal " << type << " is destructed." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other): type(other.type){
    
    std::cout << "WrongAnimal is copied to " << type << "." << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other){
    if (this != &other)
    {
        type = other.type;
        std::cout << "WrongAnimal copy assignment constructor is called." << std::endl; 
    }
    return (*this);
}

const std::string& WrongAnimal::getType() const{
    return (type);
}

void WrongAnimal::makeSound() const{
    std::cout << "NO Sound for WrongAnimal" << std::endl;
}