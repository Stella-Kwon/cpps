/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skwon2 <skwon2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 20:09:22 by skwon2            #+#    #+#             */
/*   Updated: 2025/01/08 11:45:41 by skwon2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(){

    ClapTrap a ("a");
    ClapTrap b ("b");

    std::cout << "\n\n"<< std::endl; 
    
    std::cout << "ClapTrap a" << std::endl;
    std::cout << "name : " << a.getName() << std::endl;
    std::cout << "hitpoints : " << a.getHitPoints() << std::endl;
    std::cout << "energypoints : " << a._getEnergyPoints() << std::endl;
    std::cout << "attackDamagepoints : " << a._getAttackDamagePoints() << std::endl;
    
    std::cout << "\n\n"<< std::endl; 
    
    std::cout << "ClapTrap b" << std::endl;
    std::cout << "name : " << b.getName() << std::endl;
    std::cout << "hitpoints : " << b.getHitPoints() << std::endl;
    std::cout << "energypoints : " << b._getEnergyPoints() << std::endl;
    std::cout << "attackDamagepoints : " << b._getAttackDamagePoints() << std::endl;
    
    std::cout << "\n\n"<< std::endl; 

    a.attack("b");
    // b.takeDamage(a._getAttackDamagePoints());
    b.takeDamage(5);
    b.beRepaired(10);

    std::cout << "\n\n"<< std::endl; 
    
    b.attack("a");
    // a.takeDamage(b._getAttackDamagePoints());
    a.takeDamage(5);
    a.beRepaired(10);
    return 0;
}