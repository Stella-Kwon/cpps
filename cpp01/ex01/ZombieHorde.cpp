/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skwon2 <skwon2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 20:50:55 by skwon2            #+#    #+#             */
/*   Updated: 2024/12/03 21:32:40 by skwon2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name) // copy name not reference name. so that every array has its on independent value of it.
{
    if (N == 0)
        return (nullptr);
    //it is a pointer
    Zombie *zombie = new Zombie[N]; // by calling it like this will construct N amout of array of Zombies;
    int i = 0;
    while (i < N)
        zombie[i++].setName(name);
    return (zombie);
}

//worng.
// Zombie* zombieHorde(int N, std::string name)
// {
//     if (N == 0)
//         return (nullptr);
//     //it is a pointer so should allocate memory
//     Zombie *zombie;
//     int i = 0;
//     while (i < N)
//         //this part also even allocated with new, so zombie[i] has proper place to store;
//         // zombie[i] need to copy the value but Zombie(name)will return the Zombie itself
//         zombie[i++]= Zombie(name);
//     return (zombie);
// }