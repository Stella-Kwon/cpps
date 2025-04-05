/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skwon2 <skwon2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:57:21 by skwon2            #+#    #+#             */
/*   Updated: 2025/01/22 12:41:55 by skwon2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cat.hpp"

Cat::Cat(): Animal(), brain(new Brain()), type("Cat"){
    // type = "Cat";
    std::cout << "Cat " << type << " is created." << std::endl;
}

Cat::~Cat(){
    std::cout << "Cat " << type << " is destructed." << std::endl;
    delete brain; // should be here to print the printing in the right order.
}

Cat::Cat(const Cat& other): Animal(other), brain(new Brain(*other.brain)){
    type = "Cat";
    std::cout << "Cat is copied to " << type << "." << std::endl;
}

Cat& Cat::operator=(const Cat& other){
    if (this != &other)
    {
        Animal::operator=(other);
        delete brain;
        brain = new Brain(*other.brain);
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

Brain* Cat::getBrain() const {
    return brain;
}