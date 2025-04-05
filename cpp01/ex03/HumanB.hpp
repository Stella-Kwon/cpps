/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skwon2 <skwon2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 22:01:57 by skwon2            #+#    #+#             */
/*   Updated: 2024/12/04 00:13:36 by skwon2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_B_HPP
#define HUMAN_B_HPP

#include "Weapon.hpp"

class HumanB{
    private:
        Weapon* _weapon = nullptr; // better habbit to init to null.
        //HumanB does not need to have weapon when it initiate.
        // so this does not has to be exit everytime.
        // that is why using pointer, so it does not create by calling HumanB(),
        // unless we need to set.
        std::string _name;
    public:
        HumanB(const std::string& name);
        ~HumanB();
        void attack() const;
        void setWeapon(Weapon& weapon);
};

#endif