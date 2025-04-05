/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skwon2 <skwon2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:51:22 by skwon2            #+#    #+#             */
/*   Updated: 2025/01/15 12:00:18 by skwon2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "animal.hpp"

Animal::Animal(): type("Empty"){
    std::cout << "Animal " << type << " is created." << std::endl;
}

Animal::~Animal(){
    std::cout << "Animal " << type << " is destructed." << std::endl;
}

Animal::Animal(const Animal& other): type(other.type){
    
    std::cout << "Animal is copied to " << type << "." << std::endl;
}

Animal& Animal::operator=(const Animal& other){
    if (this != &other)
    {
        type = other.type;
        std::cout << "Animal copy assignment constructor is called." << std::endl; 
    }
    return (*this);
}

const std::string& Animal::getType() const{
    return (type);
}

void Animal::makeSound() const{
    std::cout << "NO Sound for Animal" << std::endl;
}