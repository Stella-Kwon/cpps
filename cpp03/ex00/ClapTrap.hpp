/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skwon2 <skwon2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 20:09:32 by skwon2            #+#    #+#             */
/*   Updated: 2025/01/15 16:36:41 by skwon2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

# include <string> 
# include <iostream>

class ClapTrap{
    private: 
        std::string _name;
        unsigned int _hitPoints;
        unsigned int _energyPoints;
        unsigned int _attackDamage;
            
    public:
        ClapTrap(const std::string& name); // virtual does not work 
        ~ClapTrap();
        ClapTrap(const ClapTrap& other);
        ClapTrap& operator=(const ClapTrap& other);

        void attack(const std::string& target);
        // void ClapTrap::attack(ClapTrap& target); // target has to be fixed :  no const
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

        std::string getName() const;
        unsigned int _getEnergyPoints() const;
        unsigned int getHitPoints() const;
        unsigned int _getAttackDamagePoints() const;
};
#endif
