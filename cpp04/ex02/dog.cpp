/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skwon2 <skwon2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:57:21 by skwon2            #+#    #+#             */
/*   Updated: 2025/01/22 12:45:03 by skwon2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dog.hpp"
// Since you are using new Brain(), 
// you must implement a copy constructor and copy assignment operator in Dog 
//to perform deep copies of the brain member.
// Using smart pointers like std::unique_ptr<Brain> instead of raw pointers is a modern and safer alternative to manage memory automatically.


Dog::Dog(): AAnimal(), brain(std::make_unique<Brain>()), type("Dog"){
    std::cout << "Dog " << type << " is created." << std::endl;
}

Dog::~Dog(){
    std::cout << "Dog " << type << " is destructed." << std::endl;
    // delete brain; // no need Delete for unique ptr
}


Dog::Dog(const Dog& other): AAnimal(other), brain(std::make_unique<Brain>(*other.brain)), type("Dog"){
    
    std::cout << "Dog is copied to " << type << "." << std::endl;
}

Dog& Dog::operator=(const Dog& other){
    if (this != &other)
    {
        AAnimal::operator=(other); // It only operates on the AAnimal part of the Dog object.
        type = other.type;
        // delete brain;
        brain = std::make_unique<Brain>(); // new will make the pointer that pointing to Brain(*other.brain)
        std::cout << "Dog copy assignment constructor is called." << std::endl; 
    }
    return (*this);
}

// using new

// Dog::Dog(): AAnimal(), brain(new Brain()), type("Dog"){
//     // type = "Dog";
//     std::cout << "Dog " << type << " is created." << std::endl;
// }

// Dog::~Dog(){
//     delete brain; // no need Delete for unique ptr
//     std::cout << "Dog " << type << " is destructed." << std::endl;
// }

// Dog::Dog(const Dog& other): AAnimal(other), brain(new Brain(*other.brain)){
    
//     std::cout << "Dog is copied to " << type << "." << std::endl;
// }

// Dog& Dog::operator=(const Dog& other){
//     if (this != &other)
//     {
//         AAnimal::operator=(other); // It only operates on the AAnimal part of the Dog object.
//         type = other.type;
//         delete brain;
//         brain = new Brain(*other.brain); // new will make the pointer that pointing to Brain(*other.brain)
//         std::cout << "Dog copy assignment constructor is called." << std::endl; 
//     }
//     return (*this);
// }

const std::string& Dog::getType() const{
    return (type);
}

void Dog::makeSound() const{
    std::cout << "Bark Bark" << std::endl;
}

const std::unique_ptr<Brain>& Dog::getBrain() const {
    return brain;
}