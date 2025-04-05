/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skwon2 <skwon2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 17:03:21 by skwon2            #+#    #+#             */
/*   Updated: 2024/12/02 22:00:35 by skwon2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_HPP
# define MAIN_HPP
# include <vector>
# include <initializer_list>
# include <iomanip>
// # include <format>
# include "PhoneBook.hpp"
// # include "Contact.hpp"

void beginingPrints();
// void prints(const std::initializer_list<std::string>& list);
std::string getInputUser(std::string ms);
void add_contact(PhoneBook *phonebook);
void search_contact(PhoneBook& phonebook);
void exit_phonebook();
#endif