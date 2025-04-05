/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skwon2 <skwon2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 22:05:53 by skwon2            #+#    #+#             */
/*   Updated: 2024/12/04 00:06:55 by skwon2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(const std::string& name) : _name(name)
{
    std::cout << "HumanB : \"" << _name << "\" has created" << std::endl;
}

HumanB::~HumanB(){
    std::cout << "HumanB : \"" << _name << "\" has destroyed" << std::endl;
}

void HumanB::setWeapon(Weapon& weapon) // there will be a weapon already initialized, gonna call from &weapon
{
    _weapon = &weapon;
}

void HumanB::attack() const {
    if (_weapon) {
        std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
    } else {
        std::cout << _name << " has no weapon to attack with" << std::endl;
    }
}