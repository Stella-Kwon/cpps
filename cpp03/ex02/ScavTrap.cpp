/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skwon2 <skwon2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 16:12:29 by skwon2            #+#    #+#             */
/*   Updated: 2025/01/15 16:40:30 by skwon2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

//Create ClapTrap with initializer list before the ScavTrap constructed.
ScavTrap::ScavTrap(const std::string& name):ClapTrap(name) {
    // with private member u cannot access like this of course,
    // so that you have to change private to protected in order to access those like this way.
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "ScavTrap " << _name << " is created." << std::endl;
};

ScavTrap::~ScavTrap(){
        std::cout << "ScavTrap " << _name << " is destroyed." << std::endl;
};

// calling inheritance with calling copy constructor
ScavTrap::ScavTrap(const ScavTrap& other):ClapTrap(other){
    // std::cout << "Copy construtor called" << std::endl;
    std::cout << "ScavTrap " << _name << " is copied to ScavTrap " << this->_name << std::endl;
};

ScavTrap& ScavTrap::operator=(const ScavTrap& other){
    // std::cout << "Copy Assignment Operator called\n";
    std::cout << "ScavTrap " << _name << " is assigned."<< std::endl;
    if (this != &other) {
        ClapTrap::operator=(other);
        std::cout << "ScavTrap " << this->_name << " assigned!" << std::endl;
    }
    return (*this);
};

void ScavTrap::attack(const std::string& target){

    if (_hitPoints > 0 && _energyPoints > 0)
    {
        _energyPoints--;
        // don't know why the param is string target not the claptrap target.
        std::cout << "ScavTrap " << _name << " fiercely attacks " << target \
        << ", is inflicting " << _attackDamage << " points of damage!" << std::endl;
    }
    else {
        std::string hitOrEnergy = \
        (_hitPoints == 0 && _energyPoints == 0) ? "both points :  hitpoints\" & \"energypoints" \
        : (_hitPoints == 0 ? "hitpoints" : "energypoints");

        std::cout << "ScabTrap " << _name << " cannot attack :: it is insufficient " \
        << hitOrEnergy << "." << std::endl;
    }
    
};

void ScavTrap::guardGate(){
    std::cout << "ScavTrap " << _name <<  " is now in Gate Keeper mode!" << std::endl;
};

//https://cdn.intra.42.fr/pdf/pdf/78668/en.subject.pdf