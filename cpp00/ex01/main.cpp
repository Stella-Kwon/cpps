/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skwon2 <skwon2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:45:48 by skwon2            #+#    #+#             */
/*   Updated: 2024/12/02 23:51:51 by skwon2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

static int Add(PhoneBook *phonebook, const std::string& cmd)
{
    if (cmd.compare("ADD") == 0 || cmd == "add")
    {
        try 
        {
            add_contact(phonebook);
        }
        catch(std::exception& e)
        {
            std::cout << "Error in adding contact: " << e.what() << std::endl;
            return 1;
        }
    }
    return 0;
}

static int Search(PhoneBook& phonebook, const std::string& cmd)
{
    if (cmd.compare("SEARCH") == 0 || cmd == "search")
    {
        try 
        {
            search_contact(phonebook);
        }
        catch(std::exception& e)
        {
            std::cout << "Error in searching contact: " << e.what() << std::endl;
            return 1;
        }
    }
    return 0;
}

int main()
{
    std::string cmd;
    PhoneBook phonebook; //By stating will call constructor PhoneBook()
    beginingPrints();
    //or
    // prints({
    // "MAKE YOUR OWN PHONEBOOK",
    // "Press Enter to continue...",
    // "--INSTRUCTION--"
    // "1. Add contacts using the ADD command.",
    // "2. Search for contacts using the SEARCH command.",
    // "3. Exit using the EXIT command."
    // });
    std::cout << "\n";
    while (1)
    {
        std::cout << "Enter a command : ADD / SEARCH / EXIT" << std::endl;
        if (!std::getline(std::cin, cmd))
        {
            std::cout << "Error reading input. Exiting...\n";
            return (1);
        }
        if (cmd.empty()) {
            std::cout << "You didn't enter anything. Please try again." << std::endl;
            continue;
        }
        if (Add(&phonebook, cmd) == 1)
        {
            break ;
        }
        else if (Search(phonebook, cmd) == 1)
        {
            break ;
        }
        else if (cmd.compare("EXIT") == 0 || cmd == "exit")
        {
            exit_phonebook();
            break ;
        }
    }
    return 0;
}