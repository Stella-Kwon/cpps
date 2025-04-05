/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skwon2 <skwon2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 22:01:57 by skwon2            #+#    #+#             */
/*   Updated: 2024/12/04 00:09:49 by skwon2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_A_HPP
#define HUMAN_A_HPP

#include "Weapon.hpp"

class HumanA{
    private:
        Weapon& _weapon; 
        // it will get direct address of weapon when HumanA()calls.
        //which means that weapon has to be exit when HumanA() calls. 
        //it will be reference to weapon when it initiate weapon by Weapon() automatically,
        //HumanA will have weapen as reference so that it can be changed.

        //  Weapon _weapon; // it will get copy of weapon when HumanA()calls. 
        //so it will be independent so that HumanA canot change as data in it.
        std::string _name;
    public:
        // HumanA(const std::string& name, const Weapon& weapon); // referencing weapon cannot be in const as they has to be in same datatype of private 
        HumanA(const std::string& name, Weapon& weapon); 
        ~HumanA();
        void attack() const;
};
#endif