/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skwon2 <skwon2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:26:37 by skwon2            #+#    #+#             */
/*   Updated: 2025/01/15 17:08:29 by skwon2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cat.hpp"
# include "dog.hpp" 
# include "wrongCat.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << meta->getType() << " " << std::endl;
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    meta->makeSound();
    i->makeSound();
    j->makeSound();
   

    delete meta; // with new need delete and it will automatically invoke destructor : without delete there will be no invoking destructors.
    delete i;
    delete j;
    
    std::cout << "\nTesting WrongAnimal and WrongCat:" << std::endl;

    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongAnimalCat = new WrongCat();

    const WrongCat* wrongCat = new WrongCat();

    wrongMeta->makeSound();
    wrongAnimalCat->makeSound();
    wrongCat->makeSound();

    delete wrongMeta;
    delete wrongAnimalCat;
    delete wrongCat;
    return 0;
}