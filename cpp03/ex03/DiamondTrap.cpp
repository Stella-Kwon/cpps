/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skwon2 <skwon2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 12:08:14 by skwon2            #+#    #+#             */
/*   Updated: 2025/01/15 10:36:50 by skwon2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(const std::string& name)
:ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
{
    this->_name = name; 
    // to make sure that the _name is from : use this-> for ensuring.
    // even claptrap has the same _name value member, automatically the parents class( base class ) value members will be hidden. =>  name hiding.
    // but for function memebers  it will always be called from base class unless using "virtual" 
    
    // if there is no same name of the value member then it will go through the parents classes and find on from there.
    this->_hitPoints = FragTrap::_hitPoints;
    this->_energyPoints = ScavTrap::_energyPoints;
    this->_attackDamage = FragTrap::_attackDamage;
    std::cout << "DiamondTrap " << this->_name << " is created." << std::endl;
}

DiamondTrap::~DiamondTrap(){
    std::cout << "DiamondTrap " << _name << " is destructed." << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
:ClapTrap(other._name + "_clap_name"), ScavTrap(other._name), FragTrap(other._name)
{
    //*this = other;// this way cannot be used as there should put initializing list for all the inherited classes.
    std::cout << "DiamonTrap " << _name << " is copied." << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
    if (this != &other)
    {
        this->_name = other._name;
        this->_hitPoints = other._hitPoints;
        this->_energyPoints = other._energyPoints;
        this->_attackDamage = other._attackDamage;
    }
    return (*this);
}

void DiamondTrap::whoAmI(){
    std::cout << "DiamondTrap is " << _name 
    << " and ClapTrap name is " << ClapTrap::_name << std::endl;
}
