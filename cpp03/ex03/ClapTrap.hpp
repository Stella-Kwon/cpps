/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skwon2 <skwon2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 20:09:32 by skwon2            #+#    #+#             */
/*   Updated: 2025/01/13 14:37:22 by skwon2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

# include <string> 
# include <iostream>

class ClapTrap{
    //private: // this will block to access without using public or protected getter setter methods
    protected : 
    // to let the derived class (who will inherits this class) to access to the base memeber without using getter setter.
    // so that it can be modified.
    // but except for derived ones, external code cannot access them directly.
        std::string _name;
        unsigned int _hitPoints;
        unsigned int _energyPoints;
        unsigned int _attackDamage;
            
    public:
        ClapTrap(const std::string& name); // virtual does not work 
        virtual ~ClapTrap();
        ClapTrap(const ClapTrap& other);
        ClapTrap& operator=(const ClapTrap& other);

        virtual void attack(const std::string& target);
        // void ClapTrap::attack(ClapTrap& target); // target has to be fixed :  no const
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

        std::string getName() const;
        unsigned int _getEnergyPoints() const;
        unsigned int getHitPoints() const;
        unsigned int _getAttackDamagePoints() const;
};
#endif
