/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skwon2 <skwon2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:26:37 by skwon2            #+#    #+#             */
/*   Updated: 2025/01/22 12:35:18 by skwon2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dog.hpp"
#include "cat.hpp"


void deepcopycheck()
{
    std::cout << "\n\nDeep copy test : Dog \n\n" << std::endl; // using same variable name in one scope need more clear expression stating {}
    {
        Dog* original = new Dog();
        
        std::string idea = "Hello, i am first.";
        original->getBrain()->setIdeas(0, idea); // idea will take as a reference automatically 
        // original->getBrain()->setIdeas(0, "직접 문자열");  // 에러: rvalue(임시값)는 non-const 레퍼런스로 받을 수 없음
        

        Dog* copy = new Dog(*original); // *original로 실제 Dog 객체를 전달 -> 알아서 레퍼런스로 가져감
        // Dog* wrong = new Dog(original);  // 에러: 포인터를 레퍼런스 매개변수에 전달할 수 없음
        std::cout << "Original idea[0] is " << original->getBrain()->getAnIdea(0) << std::endl;
        std::cout << "copy idea[0] is " << copy->getBrain()->getAnIdea(0) << std::endl;

        delete original;
        delete copy;
    }
   
    std::cout << "\n\nDeep copy test : Cat \n\n" << std::endl;
    {
        Cat* original = new Cat();
    
        std::string idea = "Hello, i am first.";
        original->getBrain()->setIdeas(0, idea); // idea will take as a reference automatically 
        // original->getBrain()->setIdeas(0, "직접 문자열");  // 에러: rvalue(임시값)는 non-const 레퍼런스로 받을 수 없음
        

        Cat* copy = new Cat(*original); // *original로 실제 Cat 객체를 전달 -> 알아서 레퍼런스로 가져감
        // Cat* wrong = new Cat(original);  // 에러: 포인터를 레퍼런스 매개변수에 전달할 수 없음
        std::cout << "Original idea[0] is " << original->getBrain()->getAnIdea(0) << std::endl;
        std::cout << "copy idea[0] is " << copy->getBrain()->getAnIdea(0) << std::endl;

        delete original;
        delete copy;
    }

}


int main()
{
    const int arraySize = 10;
    // 포인터로 선언했을 때:
    Animal* animals[arraySize]; //for the polymorphism :  need to use pointer otherwise it will only hold Animal object
    // animals[0] = new Dog();
    // animals[0]->makeSound();  // "Woof! Woof!"

    // // 포인터 없이 선언했을 때:
    // Animal animals[4];
    // // Dog를 직접 넣을 수 없음
    // animals[0].makeSound();   //"NO Sound for Animal"
    for (int i = 0; i < arraySize; i++)
    {
        if (i < arraySize/2)
            animals[i] = new Dog();
        else    
            animals[i] = new Cat();
    }
    
    for (int i = 0; i < arraySize; i++) {
        std::cout << "Animal " << i << " (Type: " << animals[i]->getType() << ") makes sound: ";
        animals[i]->makeSound();
    }

    for (int i = 0; i < arraySize; i++) {
        delete animals[i];
    }
    
    
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    std::cout << "Animal j : " << "Type: " <<  j->getType() << " makes sound: "; 
    j->makeSound();

    std::cout << "Animal i : " << "Type: " <<  i->getType() << " makes sound: "; 
    i->makeSound();
    delete j;//should not create a leak
    delete i;

    deepcopycheck();
    return 0;
}