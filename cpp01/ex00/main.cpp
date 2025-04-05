/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skwon2 <skwon2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 16:44:26 by skwon2            #+#    #+#             */
/*   Updated: 2024/12/03 21:27:18 by skwon2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    std::cout << "----------------------------------\n";
    std::cout << "<Normal Constructor>\n";
    Zombie zombie("Foo");
    zombie.announce();
    
    std::cout << "----------------------------------\n";
    std::cout << "<Heap>\n";
    Zombie* zombie_heap;
    zombie_heap = newZombie("Heap");
    zombie_heap->announce();
    delete zombie_heap; // delete will free the memory and call deconstructor
    
    std::cout << "----------------------------------\n";
    std::cout << "<Stack>\n";
    randomChump("Stack");
    std::cout << "----------------------------------\n";
    return 0;
}