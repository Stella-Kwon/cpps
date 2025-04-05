/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aanimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skwon2 <skwon2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:57:44 by skwon2            #+#    #+#             */
/*   Updated: 2025/01/22 11:25:37 by skwon2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
#define AANIMAL_HPP

# include <string>
# include <iostream>

class AAnimal{
    protected :
        std::string type;
    public :
        AAnimal();
        virtual ~AAnimal();
        AAnimal(const AAnimal& other);
        AAnimal& operator=(const AAnimal& other);

        virtual const std::string& getType() const; // CALLING AANIMAL->TYPE will be not allowed in main
        virtual void makeSound() const = 0; // = 0 makes it impossible to instantiate the Animal class :  // pure virtual function
        //if there is pure virtual function as a member in the class, 
        //it means the class is abstract class and it cannot be instantiated.(Ex : Animal() -> error)
        //However, astract class can hold ptr value.
            // Animal zoo;        // 불가능: 추상 클래스의 객체는 직접 생성할 수 없음
            // Animal* zoo;       // 가능: 추상 클래스의 포인터는 만들 수 있음
            // Animal* zoo = new Dog();  // 가능: Dog 객체를 Animal 포인터로 가리킬 수 있음
        //  An abstract class cannot be instantiated directly,
        //   but can be used as a pointer type to point to objects of its derived classes.
};

#endif