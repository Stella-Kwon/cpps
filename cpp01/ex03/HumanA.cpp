/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skwon2 <skwon2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 22:00:35 by skwon2            #+#    #+#             */
/*   Updated: 2024/12/04 00:06:39 by skwon2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(const std::string& name, Weapon& weapon) : _weapon(weapon), _name(name) // has to be in order of how you write at class
{
        std::cout << "HumanA : \"" << _name << "\" has created" << std::endl;
}

HumanA::~HumanA(){
    std::cout << "HumanA : \"" << _name << "\" has destroyed" << std::endl;
}

void HumanA::attack() const {
    if (!_weapon.getType().empty()) {
        std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
    } else {
        std::cout << _name << " has no weapon to attack with" << std::endl;
    }
}
