/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_add_exit.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skwon2 <skwon2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:41:04 by skwon2            #+#    #+#             */
/*   Updated: 2024/12/03 00:37:02 by skwon2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

static bool isDigit(const std::string& str) {
    for (char ch : str) {
        if (!std::isdigit(ch)) {
            return false;
        }
    }
    return true;
}

static std::string error_check_getinputuser(const std::string& ms)
{
    std::string str;
    try{
        str = getInputUser(ms);
    }
    catch (const std::runtime_error& e) {
        throw;
    }
    return (str);
}

void add_contact(PhoneBook *phonebook)
{
    std::cout << "\nAdding a contact...\n\n";
    
    try 
    {
        std::string firstname = error_check_getinputuser("Enter first name :");
        std::string lastname = error_check_getinputuser("Enter last name :");
        std::string nickname = error_check_getinputuser("Enter nick name :");
        std::string phonenumber = error_check_getinputuser("Enter phone number :");
        while (isDigit(phonenumber) == false)
        {
            std::cout << "Invalid input : put digit number...\n";
            phonenumber = error_check_getinputuser("Enter phone number :");
        }
        std::string secret = error_check_getinputuser("Enter the darkest secret :");
        phonebook->addContact(firstname, lastname, nickname, phonenumber, secret);
    }
    catch (const std::runtime_error& e)
    {
       throw;
    }

}

void exit_phonebook()
{
    std::cout << "\nPhonebook is closing..." << std::endl;
}

