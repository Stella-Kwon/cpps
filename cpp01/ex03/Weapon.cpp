/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skwon2 <skwon2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 22:02:45 by skwon2            #+#    #+#             */
/*   Updated: 2024/12/03 23:45:05 by skwon2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(const std::string& type) : _type(type)
{
    std::cout <<"type of weapon : " << _type << std::endl;
}

Weapon::~Weapon()
{
    std::cout <<"Weapon \"" << _type << "\" has destroyed." << std::endl;
}

const std::string& Weapon::getType() const{
    return _type;
}

void Weapon::setType(const std::string& new_type)
{
    _type = new_type;
}