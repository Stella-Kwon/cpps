/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skwon2 <skwon2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 16:44:21 by skwon2            #+#    #+#             */
/*   Updated: 2024/12/03 20:15:54 by skwon2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void randomChump(std::string name){
    // Zombie zombie; // it will generate zombie by initializing.
    // zombie = Zombie(name);
    
    // if there is a constructor within parameters 
    Zombie zombie(name); // just initialize it like this // storing in stack.
    zombie.announce();
}