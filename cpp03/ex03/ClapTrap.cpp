/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skwon2 <skwon2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 20:09:46 by skwon2            #+#    #+#             */
/*   Updated: 2025/01/15 16:40:44 by skwon2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string& name) 
: _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    // std::cout << "Default construtor called" << std::endl;
    std::cout << "ClapTrap " << _name << " is created." << std::endl;
}

ClapTrap::~ClapTrap(){
    // std::cout << "Destrutor called" << std::endl;
    std::cout << "ClapTrap " << _name << " is destroyed." << std::endl;
}

// ClapTrap::ClapTrap(const ClapTrap& other)
// {
//     // std::cout << "Copy construtor called" << std::endl;
//     std::cout << "ClapTrap " << _name << " is copied." << std::endl;
//     *this = other;
// }


// this is better for cpu efficiency as it initialize the value with data being copied at first
// so if you make function without initializing list and give *this = other; 
// it will call copy assignment operator in which assignment called again.
ClapTrap::ClapTrap(const ClapTrap& other)
: _name(other._name), _hitPoints(other._hitPoints), _energyPoints(other._energyPoints), _attackDamage(other._attackDamage)
{
    // std::cout << "Copy construtor called" << std::endl;
    std::cout << "ClapTrap " << _name << " is copied" << std::endl;
}

// ClapTrap::ClapTrap(const ClapTrap& other)
// {
//     std::cout << "Copy construtor called" << std::endl;
//     _name = other._name;
//     _hitPoints = other._hitPoints;
//     _energyPoints = other._energyPoints;
//     _attackDamage = other._attackDamage;
//     std::cout << "ClapTrap" << _name << "is copied" << std::endl;
// }


ClapTrap& ClapTrap:: operator=(const ClapTrap& other)
{
    
    std::cout << "Copy Assignment Operator called\n";
    std::cout << "ClapTrap " << _name << " is assigned."<< std::endl;
    if (this != &other)
    {
        _name = other._name;
        _hitPoints = other._hitPoints;
        _energyPoints = other._energyPoints;
        _attackDamage = other._attackDamage;
    }
    return (*this);
}

void ClapTrap::attack(const std::string& target){
   
    if (_hitPoints > 0 && _energyPoints > 0)
    {
        _energyPoints--;
        // don't know why the param is string target not the claptrap target.
         std::cout << "ClapTrap " << _name << " attacks " << target \
         << ", causing " << _attackDamage << " points of damage!" << std::endl;
    }
    else {
        std::string hitOrEnergy = \
        (_hitPoints == 0 && _energyPoints == 0) ? "both points :  hitpoints\" & \"energypoints" \
        : (_hitPoints == 0 ? "hitpoints" : "energypoints");

        std::cout << "ClapTrap " << _name << " failed to attack :: it has not enough " \
        << hitOrEnergy << "." << std::endl;
    }
    
};

// void ClapTrap::attack(ClapTrap& target){
   
//     if (_hitPoints > 0 && _energyPoints > 0)
//     {
//         _energyPoints--;
//         target.takeDamage(_attackDamage); // it changes so no const in pram
//          std::cout << "ClapTrap " << _name << " attacks " << target._name 
//          << ", causing " << _attackDamage << " points of damage!" << std::endl;
//     }
//     else {
//         std::string hitOrEnergy =
//         (_hitPoints == 0 && _energyPoints == 0) ? "both points :  hitpoints\" & \"energypoints"
//         : (_hitPoints == 0 ? "hitpoints" : "energypoints")

//         std::cout << "ClapTrap " << _name << " failed to attack :: it has not enough "
//         << hitOrEnergy << "." << std::endl;
//     }
    
// };

void ClapTrap::takeDamage(unsigned int amount)
{
    _hitPoints = (_hitPoints <= amount ? 0 : _hitPoints - amount);
    std::cout << "ClapTrap " << _name << " take damages of " << amount \
    << " amount of points, so that hitPoints now has : " << _hitPoints << "." << std::endl;
};

void ClapTrap::beRepaired(unsigned int amount)
{
    if (_hitPoints > 0 && _energyPoints > 0)
    {
        _energyPoints--;
        _hitPoints += amount;
        std::cout << "ClapTrap " << _name << " repaired " << amount \
     << " amount of hit points, so that hitpoints gets back to " << _hitPoints << "." << std::endl;    
    }
    else {
        std::string hitOrEnergy = \
        (_hitPoints == 0 && _energyPoints == 0) ? "both points :  hitpoints\" & \"energypoints" \
        : (_hitPoints == 0 ? "hitpoints" : "energypoints");

        std::cout << "ClapTrap " << _name << " failed to get reparied : it has not enough " \
        << hitOrEnergy << "." << std::endl;
    }
};

std::string ClapTrap::getName() const{
    return (_name);
};

unsigned int ClapTrap::_getEnergyPoints() const{
    return(_energyPoints);
};
unsigned int ClapTrap::getHitPoints() const{
    return(_hitPoints);
};
unsigned int ClapTrap::_getAttackDamagePoints() const{
    return(_attackDamage);
};