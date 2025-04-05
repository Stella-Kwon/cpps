/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skwon2 <skwon2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:57:21 by skwon2            #+#    #+#             */
/*   Updated: 2025/01/15 12:03:34 by skwon2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cat.hpp"

Cat::Cat(): Animal(){
    type = "Cat";
    std::cout << "Cat " << type << " is created." << std::endl;
}

Cat::~Cat(){
    std::cout << "Cat " << type << " is destructed." << std::endl;
}

Cat::Cat(const Cat& other): Animal(other){
    
    std::cout << "Cat is copied to " << type << "." << std::endl;
}

Cat& Cat::operator=(const Cat& other){
    if (this != &other)
    {
        type = other.type;
        std::cout << "Cat copy assignment constructor is called." << std::endl; 
    }
    return (*this);
}

const std::string& Cat::getType() const{
    return (type);
}

void Cat::makeSound() const{
    std::cout << "Meow Meow" << std::endl;
}