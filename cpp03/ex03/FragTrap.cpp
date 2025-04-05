/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skwon2 <skwon2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 16:12:29 by skwon2            #+#    #+#             */
/*   Updated: 2025/01/13 14:37:29 by skwon2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

//Create ClapTrap with initializer list before the FragTrap constructed.
FragTrap::FragTrap(const std::string& name):ClapTrap(name) {
    // with private member u cannot access like this of course,
    // so that you have to change private to protected in order to access those like this way.
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << "FragTrap " << _name << " is created." << std::endl;
};

FragTrap::~FragTrap(){
        std::cout << "FragTrap " << _name << " is destroyed." << std::endl;
};

// calling inheritance with calling copy constructor
FragTrap::FragTrap(const FragTrap& other):ClapTrap(other){
    // std::cout << "Copy construtor called" << std::endl;
    std::cout << "FragTrap " << _name << " is copied." << std::endl;
};

FragTrap& FragTrap::operator=(const FragTrap& other){
    // std::cout << "Copy Assignment Operator called\n";
    std::cout << "FragTrap " << _name << " is assigned." << std::endl;
    if (this != &other) {
        ClapTrap::operator=(other);
        std::cout << "FragTrap " << this->_name << " assigned!" << std::endl;
    }
    return (*this);
};

void FragTrap::highFivesGuys(void){
    std::cout << "FragTrap " << _name << " requests a hivefive." << std::endl;
}

//https://cdn.intra.42.fr/pdf/pdf/78668/en.subject.pdf