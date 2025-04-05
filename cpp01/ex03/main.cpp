/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skwon2 <skwon2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 20:33:59 by skwon2            #+#    #+#             */
/*   Updated: 2024/12/04 14:15:00 by skwon2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
    Weapon club = Weapon("crude spiked club");
    HumanA bob("Bob", club);
    bob.attack();
    club.setType("some other type of club");
    bob.attack();

    Weapon club2 = Weapon("crude spiked club2");
    HumanB jim("Jim"); 
    // giving "jim" like this is not std::string type, it is c-string literal, and a temporary object which cannot reference in non-const-reference.
    // so if you put datatype as HumanB(std::string& name); 
    //then it will not compile. 
    //Giving const will allow temporary object to be referenced so that give const. 
    jim.setWeapon(club2);
    jim.attack();
    club2.setType("some other type of club2");
    jim.attack();
    return 0;
}