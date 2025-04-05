/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aanimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skwon2 <skwon2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:51:22 by skwon2            #+#    #+#             */
/*   Updated: 2025/01/22 11:28:36 by skwon2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "aanimal.hpp"

AAnimal::AAnimal(): type("Empty"){
    std::cout << "AAnimal " << type << " is created." << std::endl;
}

AAnimal::~AAnimal(){
    std::cout << "AAnimal " << type << " is destructed." << std::endl;
}

AAnimal::AAnimal(const AAnimal& other): type(other.type){
    
    std::cout << "AAnimal is copied to " << type << "." << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& other){
    if (this != &other)
    {
        type = other.type;
        std::cout << "AAnimal copy assignment constructor is called." << std::endl; 
    }
    return (*this);
}

const std::string& AAnimal::getType() const{
    return (type);
}
