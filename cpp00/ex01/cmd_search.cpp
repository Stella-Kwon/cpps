/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_search.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skwon2 <skwon2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 21:14:54 by skwon2            #+#    #+#             */
/*   Updated: 2024/12/03 00:25:26 by skwon2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"


static void ten_character_wide(const std::string& word)
{
    std::string modified_word = word; //copy word
    if (word.length() > 10)
        modified_word = modified_word.substr(0, 9) + ".";
    std::cout << std::setw(10) << modified_word << "|";
}

static void categories(const std::initializer_list<std::string>& categories)
{
    std::cout << "------------------------------------------------------------\n";
    for (const auto& list : categories)
    {
        ten_character_wide(list);
    }
    std::cout << "|" << std::endl;
}

static void categories_contents(const Contact& contact, int i)
{
     std::cout << "------------------------------------------------------------\n";
    // ten_character_wide(std::format("{}", i));
    std::string str = std::to_string(i);
    ten_character_wide(str);
    ten_character_wide(contact.getFirstName());
    ten_character_wide(contact.getLastName());
    ten_character_wide(contact.getNickName());
    std::cout << "|" << std::endl;
     std::cout << "------------------------------------------------------------\n";
}

static int prints_each_categories(const Contact& contact)
{
    if (contact.getFirstName().empty())
        return 1;
    std::cout << "------------------------------------------------------------\n";
    std::cout << "First_name | " << contact.getFirstName() << std::endl;
     std::cout << "------------------------------------------------------------\n";
    std::cout << "Last_name | " << contact.getLastName() << std::endl;
     std::cout << "------------------------------------------------------------\n";
    std::cout << "Nick_name | " << contact.getNickName() << std::endl;
     std::cout << "------------------------------------------------------------\n";
    std::cout << "Phone_number | " << contact.getPhoneNumber() << std::endl;
     std::cout << "------------------------------------------------------------\n";
    std::cout << "Darkest_secret" << contact.getDarkestSecret() << std::endl;
    std::cout << "------------------------------------------------------------\n";
    return 0;
}


void get_index_contents(PhoneBook& phonebook)
{    
    std::cout << "Enter a index to see more specifically...\n";
    std::string index;
    if (!std::getline(std::cin, index))
    {
        std::cout << "Error reading input. Searching...\n";
        throw std::runtime_error("Error reading input. Searching...");
    }
    if (index.empty())
        return get_index_contents(phonebook);
    int i = std::stoi(index);
    if (i >= MAX_CONTACT)
    {
        std::cout << "Range should be within 0 - 7...\n";
        return get_index_contents(phonebook);
    }
    if (prints_each_categories(phonebook.getElementContact(i)) == 1)
    {
        std::cout << "Nothing has stored...\n";
        return get_index_contents(phonebook);
    }
}

void search_contact(PhoneBook& phonebook)
{
    std::cout << "Searching...\n";
   
    categories({
        "index",
        "first name",
        "last name",
        "nickname"
    });
    for(int i = 0; i < MAX_CONTACT; i++)
        categories_contents(phonebook.getElementContact(i), i);
    try {
        get_index_contents(phonebook);
    }
    catch(std::runtime_error& e){
        throw;
    }
}
