/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skwon2 <skwon2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 16:44:26 by skwon2            #+#    #+#             */
/*   Updated: 2024/12/03 21:34:15 by skwon2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

static void test_free(Zombie *zombies, int N)
{

    //while (Zombies[i])// can cause a problem of having a unintailized value inside still after new malloc; 
    //Zombie* zombies = new Zombie[N]; // will give only that amount of the array, not ending with \0 or NULL;
    for(int i = 0; i < N; i++)
    {
        // std::cout << i << ": ";
        zombies->announce();
        // delete zombie[i]; // this cannot work becasue zombies itself is one whole memory block, amd delete only works with pointer.
    }
    delete[] zombies; //should use delete[] for pointer pointing to array;
}

int main()
{
    Zombie *zombies;
    zombies = zombieHorde(10, "Foo");
    test_free(zombies, 10);
    return 0;
}