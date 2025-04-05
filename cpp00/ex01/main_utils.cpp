/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skwon2 <skwon2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:39:14 by skwon2            #+#    #+#             */
/*   Updated: 2024/12/02 23:27:36 by skwon2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

//auto can be in anytype; // helps to read easily and for later maintanence.
//std::vector<daytype>::name;
// const auto& : reading version, no copy or changes;

void beginingPrints()
{
    std::vector<std::string> instructions = {
        "MAKE YOUR OWN PHONEBOOK",
        "Press Enter to continue...",
        "--INSTRUCTION--",
        "1. Add contacts using the ADD command.",
        "2. Search for contacts using the SEARCH command.",
        "3. Exit using the EXIT command."
    };
    for(const auto& prints : instructions)
    {
        std::cin.get();
        std::cout << prints << std::endl;
    }
}
// ------other printing style----------
// void prints(std::initializer_list<std::string> list)
// {
//     for(const auto& prints : list)
//     {
//         std::cin.get();
//         std::cout << prints << std::endl;
//     }
// }

//Reusable function stlye of printing
// initializer_list can hold a list : so you can now call list in parameter
// initialize_list is immutable which are constant data, so compiler would not want you to reference the data
// like this => std::initializer_list<std::string>& 
// so that then you should put const in front first to specify : 
// const std::initializer_list<std::string>& list => maybe better this way that memory does not get wasted
// better to use const so that std::intitialize_list is confirmed again, there will be no changes.
void prints(const std::initializer_list<std::string>& list)
{
    for (const auto& prints : list)
    {
        std::cin.get();
        std::cout << prints << std::endl;
    }
}


std::string getInputUser(std::string ms)
{
    std::string input;
    std::cout << ms << std::endl;
    if (!std::getline(std::cin, input))
    {
        std::cout << "Error reading input. Adding...\n";
        throw std::runtime_error("Error reading input. Adding...");
    }
    //std::cin >> first;
    //you could have used it like this but this will only git you th first word.
    //delimeter for here will be any spaces or \n.
    std::cout << "You entered: \"" << input << "\"\nPress Enter if it is right or Press NO/no if you want to edit" << std::endl;
    
    std::string answer;
    if (!std::getline(std::cin, answer))
    {
        std::cout << "Error reading input. Adding...\n";
        throw std::runtime_error("Error reading input. Adding...");
        // when you call throw it will go back to where this function call from
        // transfer control to the nearest 'catch' block
        // while doing that it will unwind the stack memories
        // which destroys all local varialbes in reverse way from where it called and got back to.
        // where it call getInputUser ~~where it passes (if they do) ~~add_contact() where catch block is.
    }
    if (answer == "NO" || answer == "no")
    {
        std::cout << "\n";
        return getInputUser(ms);
    }
    if (input.empty()) 
    {
        std::cout << "You didn't enter anything. Please try again." << std::endl;
        return getInputUser(ms);
    }
    return input;
}
