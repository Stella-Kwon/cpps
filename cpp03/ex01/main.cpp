/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skwon2 <skwon2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 20:09:22 by skwon2            #+#    #+#             */
/*   Updated: 2025/01/12 11:34:09 by skwon2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(){
    ScavTrap a("a");
    ScavTrap b(a);
    // ScavTrap* c =  new ClapTrap("d");// cannot assign base object to the derived object
    // becasue base object cannot hold all the value of ScavTrap.
    ClapTrap* c = &b; //using polymorphism with inheritance
    ClapTrap* d = new ScavTrap("c");//using polymorphism with inheritance
    //ClapTrap* c = &ScavTrap("d");//error: taking the address of a temporary object of type 'ScavTrap'
    a.attack("b");
    c->attack("d");
    d->attack("c");
    // d->guardGate(); // the member only assigned at the Scavtrap cannot be called.
    b.takeDamage(a._getAttackDamagePoints());
    b.guardGate();
    c->takeDamage(d->_getAttackDamagePoints());


    delete d; // you need ClapTrap to call virtual ~Claptrap;
//    when using polymorphism with inheritance, 
// (in which a base class pointer or reference can point to objects of derived classes
// , and the appropriate function or method is called based on the actual object type (not the pointer/reference type).)
//    if you delete a derived class object through a base class pointer, 
//    and the base class does not have a virtual destructor, 
//    only the base class destructor is called, not the derived class destructor.

// using virtual on fucntions
// 1. when inherited class has the same function name in the derived function 
// and when you want to call the derived one. you call with virtual and override
// 2. when you use polymorphism with inheritance, you need to give virtual to make sure 
// what function you have to call based on actual type object. //destructor and stuff. => dynamically dispatched as it takes within runtime.

//using virtual on object class : virtual inheritance
// 3. when one intances of common base class is shared by the derived class, inherits from it multiple times,
// // you will encounter a problem of ambiguity which version of shared base class should be used . 
//This diamond problem happens when you have multiple inheritance paths leading to the same base class.
// Using virtual inheritance helps to solve this problem by ensuring that the base class is only inherited once,
// avoiding ambiguities and conflicts.



//Aspect : 	Non-Virtual Function	/    Virtual Function
// Dispatch Mechanism : 	Compile-time (static distpatch)	/    Runtime (dynamic dispatch)
// Which Function is Called :	Based on the pointer/reference  /   type	Based on the actual object type
// Overriding Behavior : 	Function hiding (not true overriding): calls based function  /  True overriding
// Performance	:   Slightly faster (no runtime check)	/   Slightly slower (runtime check)
    return 0;
};