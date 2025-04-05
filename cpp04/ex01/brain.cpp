/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skwon2 <skwon2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:10:03 by skwon2            #+#    #+#             */
/*   Updated: 2025/01/15 20:40:30 by skwon2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "brain.hpp"

Brain::Brain(){
    std::cout << "Brain is created." << std::endl;
}

Brain::~Brain(){
    std::cout << "Brain is destructed." << std::endl;
}

//with std::array c++style arrays
Brain::Brain(const Brain& other):ideas(other.ideas){
    std::cout << "Brain is copied." << std::endl;
}

// if you have c style of arrays then you have to copy each of element manually
// Brain::Brain(const Brain& other){
//     for (int i = 0 ; i < 100 ; i++)
//     {
//         ideas[i] = other.ideas[i];
//     }
//     std::cout << "Brain is copied." << std::endl;
// }

Brain& Brain::operator=(const Brain& other){
    if (this != &other)
    {
        //with c style array expression
        // for(int i = 0;  i < 100; i++)
        // {
        //     ideas[i] = other.ideas[i];
        // }

        //with c++style arrays
        ideas = other.ideas;
        std::cout << "Brain copy assignment operator called." << std::endl;
    }
    return *this;
}

// // 1. const auto& - Use when you just want to read values
// for (const auto& num : numbers) {
//     std::cout << num << std::endl;  // Can't modify num
// }

// // 2. auto& - Use when you need to modify the original values
// for (auto& num : numbers) {
//     num *= 2;  // This changes the actual values in numbers
// }

// // 3. auto - Use when you want a copy (usually not recommended)
// for (auto num : numbers) {
//     num *= 2;  // Only modifies the copy, not the original
// }


//with c style arrays;
//// std::string& Brain::getIdeas() const{ // not reference because it avoids the danger of returning a reference to a local variable.
// std::string Brain::getIdeas() const{

//     std::stringstream stringInOne;
//     for (const auto& idea: ideas)
//     {
//         stringInOne << idea << " "; 
//     }
//     std::string res = stringInOne.str();
//     return res;
// }

// std::string Brain::getAnIdea(int index) const{

//     //std::vector<std::string> ideas = {"idea1", "idea2", "idea3"};
//     //index < ideas.size() it will give you th current number of elements in the vector
//     if (index < 100 && index >= 0)
//     {
//         return (ideas[index]);
//     }
//     return "";
// }



//with c++ arrays
std::string Brain::getIdeas() const{

    std::stringstream stringInOne;
    for (const auto& idea: ideas)
    {
        stringInOne << idea << " "; 
    }
    std::string res = stringInOne.str();
    return res;
}

std::string Brain::getAnIdea(int index) const{

    //std::vector<std::string> ideas = {"idea1", "idea2", "idea3"};
    //index < ideas.size() it will give you th current number of elements in the vector
    if (index >= 0 && index < 100) //  it is the smae as the array is set as 100 as well
    {
        return (ideas[index]);
    }
    return "";
}


void Brain::setIdeas(int index, std::string& idea){
    if (index >= 0 && index < 100) //  it is the smae as the array is set as 100 as well
    {
        ideas[index] = idea;
    }
    else 
        std::cout << "Index out of bounds!" << std::endl;
}
