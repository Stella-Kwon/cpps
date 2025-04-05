/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skwon2 <skwon2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 20:09:22 by skwon2            #+#    #+#             */
/*   Updated: 2025/01/12 11:36:22 by skwon2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main(){
    FragTrap a("a");
    FragTrap b(a);
   
    a.attack("b");
    b.highFivesGuys();
    b.takeDamage(a._getAttackDamagePoints());
    return 0;
}